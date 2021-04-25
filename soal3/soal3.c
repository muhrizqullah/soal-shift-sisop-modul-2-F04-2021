#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <wait.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <sys/stat.h>
#include <syslog.h>

char pesanChyper[50];

void Chyper(char text[])
{
    int i;
    for (i = 0; i < strlen(text); i++)
    {
        char ch = text[i];
        if (ch == ' ')
        {
            pesanChyper[i] = ' ';
            continue;
        }
        if (isupper(ch))
        {
            pesanChyper[i] = (char)(ch - 'A' + 5) % 26 + 'A';
            continue;
        }
        if (islower(ch))
        {
            pesanChyper[i] = (char)(ch - 'a' + 5) % 26 + 'a';
            continue;
        }
    }
}

void zip_it(char *name)
{
    pid_t child_id;
    int status;

    child_id = fork();

    if (child_id < 0)
        exit(EXIT_FAILURE);

    if (child_id == 0)
    {
        char *argv[] = {"zip", "-rm", name, name, "status.txt", NULL};
        execv("/usr/bin/zip", argv);
        exit(EXIT_SUCCESS);
    }
}


void wget_img(char* link, char* name)
{
    pid_t child_id;
    int status;

    child_id = fork();

    if (child_id < 0)
        exit(EXIT_FAILURE);

    if (child_id == 0)
    {
        char *argv[] = {"wget", link, "-q", "-O", name, NULL};
        execv("/usr/bin/wget", argv);
        exit(EXIT_SUCCESS);
    }
}

void download_img(char *location)
{
    pid_t child_id;
    int status;

    child_id = fork();
    if (child_id < 0)
    {
        exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
    }

    if (child_id == 0)
    {
        chdir(location);
        char waktusekarang[50], link[50];
        int i;
        for (i = 0; i < 10; i++)
        {
            time_t t_now = time(NULL);
            struct tm waktu = *localtime(&t_now);
            strftime(waktusekarang, sizeof(waktusekarang) - 1, "%Y-%m-%d_%H:%M:%S", &waktu);
            snprintf(link, sizeof(link) - 1, "https://picsum.photos/%ld", (t_now % 1000) + 50);

            wget_img(link, waktusekarang);

            sleep(5);
        }
        
        Chyper("Download Success");
        FILE *chy;
        chy = fopen("status.txt", "w");
        fprintf(chy, "%s", pesanChyper);
        fclose(chy);

        exit(EXIT_SUCCESS);
    }
    else
    {
        while (wait(&status) > 0);

        zip_it(location);
    }
}

void mk_dir(char *name)
{
    pid_t child_id;
    int status;

    child_id = fork();
    if (child_id < 0)
    {
        exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
    }

    if (child_id == 0)
    {
        char *argv[] = {"mkdir", "-p", name, NULL};
        execv("/bin/mkdir", argv);
        exit(EXIT_SUCCESS);
    }
    else
    {
        while (wait(&status) > 0);
        download_img(name);
    }
}

int main(int argc, char **argv)
{
    int status;
    if (argc != 2)
    {
        printf("Pilih mode\n-x : Menjalankan program, dan menghapus saat selesai\n-z : Stop Program\n");
        exit(EXIT_SUCCESS);
    }

    FILE *killer;
    killer = fopen("killer.sh", "w");
    if (strcmp(argv[1], "-z") == 0)
    {
        fprintf(killer, "#!/bin/bash\nkillall soal3\nrm \"$0\"");
    }
    else if (strcmp(argv[1], "-x") == 0)
    {
        fprintf(killer, "#!/bin/bash\narr=($(ps -aux | grep './soal3' | awk '{ print $2 }'))\nkill -9 ${arr[0]}\nrm \"$0\"");
    }
    fclose(killer);

    pid_t pid, sid;
    pid = fork();
    if (pid < 0)
    {
        exit(EXIT_FAILURE);
    }
    if (pid > 0)
    {
        exit(EXIT_SUCCESS);
    }
    umask(0);
    sid = setsid();
    if (sid < 0)
    {
        exit(EXIT_FAILURE);
    }
    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    while (1)
    {
        char waktusekarang[50], link[50];

        time_t t_now = time(NULL);
        struct tm waktu = *localtime(&t_now);
        strftime(waktusekarang, sizeof(waktusekarang) - 1, "%Y-%m-%d_%H:%M:%S", &waktu);

        pid_t child_id;
        int status;

        child_id = fork();

        if (child_id < 0)
        {
            exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
        }

        if (child_id == 0)
        {
            mk_dir(waktusekarang);
            exit(EXIT_SUCCESS);
        }

        sleep(40);
    }
}
