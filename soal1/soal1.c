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
#include <glob.h>

char path[20];
short flag=0;

void filter_prosess(char* sumber, char* tujuan)
{
    pid_t child_id;
    int status;

    child_id = fork();

    if (child_id < 0)
        exit(EXIT_FAILURE);

    if (child_id == 0)
    {
    glob_t globbuf_film;
    globbuf_film.gl_offs = 2;
    glob(sumber, GLOB_DOOFFS, NULL, &globbuf_film);
    glob(tujuan, GLOB_DOOFFS | GLOB_APPEND, NULL, &globbuf_film);
    globbuf_film.gl_pathv[0] = "cp";
    globbuf_film.gl_pathv[1] = "-r";
    execvp("cp", &globbuf_film.gl_pathv[0]);
    exit(1);
    }
}

void hbd(){
  int status,status2;
  time_t t_now = time(NULL);
  struct tm waktu = *localtime(&t_now);

while(wait(&status2)>0);

  while(strcmp(path,"09-04_22:22") !=0){
    sleep(2);
    t_now = time(NULL);
    waktu = *localtime(&t_now);
    strftime(path, sizeof(path)-1, "%d-%m_%H:%M", &waktu);
    }

  pid_t child_id;
  child_id = fork();

  if (child_id < 0) {
    exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  } 

  if (child_id == 0) {
    char *argv_6[] = {"rm","-rf", "MUSIK", "FOTO", "FILM", NULL};
    execv("/bin/rm", argv_6);
  } else{
    while(wait(&status)>0);
    char *argv_4[] = {"zip", "-rm", "Lopyu_Stevany", ".", "-x", "soal1*", "*.zip", NULL};
    execv("/bin/zip", argv_4);
    flag=0;
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
      exit(1);
    }
}

void download(){  
  pid_t child_id;
  int i,j,status,status1,status2,status3,status4,status5,status6;
  child_id = fork();

  if (child_id < 0) {
    exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  } 

  if (child_id == 0) {
    // this is child
    char *argv[3][2] = {    
    {"https://drive.google.com/uc?id=1ZG8nRBRPquhYXq_sISdsVcXx5VdEgi-J&export=download", "Musik_for_Stevany.zip"},
    {"https://drive.google.com/uc?id=1FsrAzb9B5ixooGUs0dGiBr-rC7TS9wTD&export=download", "Foto_for_Stevany.zip"},
    {"https://drive.google.com/uc?id=1ktjGgDkL0nNpY-vT7rT7O6ZI47Ke9xcp&export=download", "Film_for_Stevany.zip"}};
    for(i = 0; i< 3;i++ ){
      wget_img(argv[i][0], argv[i][1]);
      }
    }
   else{
    // this is parent
    // sleep(40);
    while ((wait(&status2)) > 0);
    // kill(child_id, SIGKILL); 
    // while ((wait(&status3)) > 0);
    pid_t child_id1;
    child_id1 = fork();
    
  if (child_id1 < 0) {
    exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  } 

  if (child_id1 == 0) {
    char *argv_3[] = {"unzip", "*.zip", NULL};
    execv("/usr/bin/unzip", argv_3); 
  }else{
    while ((wait(&status4)) > 0);
    id_t child_id2;
    child_id2 = fork();

  if (child_id2 < 0) {
    exit(EXIT_FAILURE);
  }  

  if(child_id2==0){
    while ((wait(&status)) > 0);
    char *argv_1[] = {"mkdir", "-p", "Musyik", "Fylm", "Pyoto", NULL};
    execv("/bin/mkdir", argv_1);
  }else{
      while ((wait(&status5)) > 0);
      id_t child_id3;
      child_id3 = fork();

      if (child_id3 < 0) {
      exit(EXIT_FAILURE);
      }  

      if(child_id3==0){
      char *argv_filter[3][2] = {    
      {"FILM/*.mp4", "Fylm/"},
      {"FOTO/*.jpg", "Pyoto/"},
      {"MUSIK/*.mp3", "Musyik/"}};
      for(i = 0; i< 3;i++ ){
      filter_prosess(argv_filter[i][0], argv_filter[i][1]);
      }
      
      }else{
         while ((wait(&status6)) > 0);
        hbd();
        // return;
      } 
    }    
    }
}

}
int main() {
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

  time_t my_time;
  struct tm *timeinfo; 
  while(1){
  time (&my_time);
  timeinfo = localtime (&my_time);
  if(timeinfo->tm_mday == 9 && timeinfo->tm_mon+1 == 4 && timeinfo->tm_hour == 16 && timeinfo->tm_min == 22 && flag==0){
    download();
    flag=1;
  }
  sleep(2);
  }
}
