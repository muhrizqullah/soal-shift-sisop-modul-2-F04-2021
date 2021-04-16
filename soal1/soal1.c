#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>
#include <time.h>
#include <string.h>
#include <glob.h>

char path[20];

void filter(){
  int status,status1,status2;
    if (0 == fork()) {
    glob_t globbuf_film;
    globbuf_film.gl_offs = 2;
    glob("FILM/*.mp4", GLOB_DOOFFS, NULL, &globbuf_film);
    glob("Fylm/", GLOB_DOOFFS | GLOB_APPEND, NULL, &globbuf_film);
    globbuf_film.gl_pathv[0] = "cp";
    globbuf_film.gl_pathv[1] = "-r";
    execvp("cp", &globbuf_film.gl_pathv[0]);
    }
    while ((wait(&status)) > 0);

    if(0==fork()){
    glob_t globbuf_foto;
    globbuf_foto.gl_offs = 2;
    glob("FOTO/*.jpg", GLOB_DOOFFS, NULL, &globbuf_foto);
    glob("Pyoto/", GLOB_DOOFFS | GLOB_APPEND, NULL, &globbuf_foto);
    globbuf_foto.gl_pathv[0] = "cp";
    globbuf_foto.gl_pathv[1] = "-r";
    execvp("cp", &globbuf_foto.gl_pathv[0]);
    }
    while ((wait(&status1)) > 0);

    if(0==fork()) {
    glob_t globbuf;
    globbuf.gl_offs = 2;
    glob("MUSIK/*.mp3", GLOB_DOOFFS, NULL, &globbuf);
    glob("Musyik/", GLOB_DOOFFS | GLOB_APPEND, NULL, &globbuf);
    globbuf.gl_pathv[0] = "cp";
    globbuf.gl_pathv[1] = "-r";
    execvp("cp", &globbuf.gl_pathv[0]);
    }
    while ((wait(&status2)) > 0);
}

void hbd(){
  int status,status2;
  time_t t_now = time(NULL);
  struct tm waktu = *localtime(&t_now);

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
    exit(1);
  }
}
void download(){  
  pid_t child_id;
  int i,status,status1,status2,status3,status4,status5,status6;
  child_id = fork();

  if (child_id < 0) {
    exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  } 

  if (child_id == 0) {
    // this is child
    char *argv[3][7] = {    
    {"/usr/bin/wget", "wget", "--no-check-certificate", "https://drive.google.com/uc?id=1ZG8nRBRPquhYXq_sISdsVcXx5VdEgi-J&export=download", "-O", "Musik_for_Stevany.zip", 0},
    {"/usr/bin/wget", "wget", "--no-check-certificate", "https://drive.google.com/uc?id=1FsrAzb9B5ixooGUs0dGiBr-rC7TS9wTD&export=download", "-O", "Foto_for_Stevany.zip", 0},
    {"/usr/bin/wget", "wget", "--no-check-certificate", "https://drive.google.com/uc?id=1ktjGgDkL0nNpY-vT7rT7O6ZI47Ke9xcp&export=download", "-O", "Film_for_Stevany.zip", 0}};
    for(i = 0; i< 3;i++ ){
      if (0 == fork()){
        while ((wait(&status1)) > 0);
        continue;
      } 
      while ((wait(&status2)) > 0);
      execv("/usr/bin/wget", &argv[i][0]);     
    }         
    }
   else{
    // this is parent
    while ((wait(&status3)) > 0);
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
      filter();
      }else{
         while ((wait(&status6)) > 0);
        hbd();
      } 
    }    
    }
}
}
int main() {
  int status,status1;
  time_t t_now = time(NULL);
  struct tm waktu = *localtime(&t_now);
  strftime(path, sizeof(path)-1, "%d-%m_%H:%M", &waktu);
  while(strcmp(path,"09-04_16:22")!=0)
  {
    sleep(2);
    t_now = time(NULL);
    waktu = *localtime(&t_now);
    strftime(path, sizeof(path)-1, "%d-%m_%H:%M", &waktu);
  }
  download();
  return 0;
}
