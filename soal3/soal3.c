#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <wait.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

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

int main() {

//   while(true){
  char waktusekarang[50],waktusekarang2[50], link[50];
  int status, status1, status2, i;
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
    fprintf(chy, pesanChyper);
    fclose(chy);
    
    while ((wait(&status)) > 0);
    chdir("..");
    if(fork() == 0){
    char *argv_2[] = {"zip", "-rm", waktusekarang2, waktusekarang2, "status.txt", NULL};
    execv("/usr/bin/zip", argv_2);
    }
//   sleep(40);
// }
}
