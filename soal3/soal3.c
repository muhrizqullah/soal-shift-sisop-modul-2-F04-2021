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

void Chyper(char text[]){
  int i;
  for(i=0; i < strlen(text); i++){
    char ch = text[i];
        if (ch == ' ')
        { pesanChyper[i]=' ';
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

int main(int argc, char** argv)  {
  int status;
  if(argc != 2) {
        printf("Pilih mode\n-x : Menjalankan program, dan menghapus saat selesai\n-z : Stop Program\n");
        exit(EXIT_SUCCESS);
  }

  FILE* killer;
  killer = fopen("killer.sh", "w");
  if(strcmp(argv[1],"-z")==0){
    fprintf(killer, "#!/bin/bash\nkillall ./soal3\nrm \"$0\"");
  }else if(strcmp(argv[1],"-x")==0){
    fprintf(killer, "#!/bin/bash\nkill -9 %d\nrm \"$0\"",(int)getpid());
  }
  fclose(killer);

  if(fork()==0){
    char *argv_1[] = {"chmod", "+w", "killer.sh", NULL};
    execv("/bin/chmod", argv_1);
  }

  while(wait(&status) > 0);

  pid_t pid, sid;
  pid = fork();
  if (pid < 0) {
    exit(EXIT_FAILURE);
  }
  if (pid > 0) {
    exit(EXIT_SUCCESS);
  }
  umask(0);
  sid = setsid();
  if (sid < 0) {
    exit(EXIT_FAILURE);
  }
  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);

  while(1){
  char waktusekarang[50],waktusekarang2[50], link[50];
  int status, status1, status2,status3, i;
  time_t t_now = time(NULL);
  struct tm waktu = *localtime(&t_now);
  strftime(waktusekarang, sizeof(waktusekarang)-1, "%Y-%m-%d_%H:%M:%S", &waktu);

  pid_t child_id;

  child_id = fork();

  if (child_id < 0) {
    exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  }

  if (child_id == 0) {
    // this is child
    char *argv[] = {"mkdir", "-p", waktusekarang, NULL};
    execv("/bin/mkdir", argv);
  } 
    while ((wait(&status)) > 0);
    chdir(waktusekarang);
    strcat(waktusekarang2,waktusekarang);
    for(i = 0; i < 10; i++){
        t_now = time(NULL);
        waktu = *localtime(&t_now);
        strftime(waktusekarang, sizeof(waktusekarang)-1, "%Y-%m-%d_%H:%M:%S", &waktu);
        snprintf(link, sizeof(link)-1, "https://picsum.photos/%ld", (t_now%1000) + 50);
        if(fork() == 0){
        char *argv_1[] = {"wget", link, "-O", waktusekarang,  NULL};
        execv("/usr/bin/wget", argv_1);
        }
        sleep(5);
    }

    Chyper("Download Success");
    FILE* chy;
    chy = fopen("status.txt", "w");
    fprintf(chy, "%s", pesanChyper);
    fclose(chy);
    
    while ((wait(&status1)) > 0);
    chdir("..");
    if(fork() == 0){
    char *argv_2[] = {"zip", "-rm", waktusekarang2, waktusekarang2, "status.txt", NULL};
    execv("/usr/bin/zip", argv_2);
    }

    while ((wait(&status2)) > 0);

  sleep(40);
}
}
