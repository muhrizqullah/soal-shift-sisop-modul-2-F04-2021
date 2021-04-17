#include <dirent.h>  
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <wait.h>

#include <sys/stat.h>
//execlp("unzip","unzip","-j","pets.zip","-i","*.jpg","-d","/home/gretzy/modul2/petshop",NULL);

void function1(){
  pid_t child_id;
  int status;

  child_id = fork();
  
  if (child_id < 0) {
    exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
	
  }

  if (child_id == 0) {
    // this is child
    
    char *argv[] = {"mkdir","/home/gretzy/modul2/", NULL};
    execv("/bin/mkdir", argv);
    
  } else {
 
    // this is parent
    while ((wait(&status)) > 0);
   execlp("unzip","unzip","-j","/home/gretzy/soal-shift-2-local/pets.zip","-i","*.jpg","-d","/home/gretzy/modul2/petshop",NULL);

    
   }
   
}



void function211111(char token[],char * nama,char * petname,char age[])
{
 pid_t child_id1;
  int status;
  child_id1 = fork();
  if (child_id1 < 0) {
  exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  }
  if (child_id1 == 0) {


chdir("/home/gretzy");
/*
FILE *f = fopen("file.txt","a");
fprintf(f,"Nama:%s\nUmur:%s\n",petname,age);
fclose(f);
*/
char *argv[] = {"echo","hai",">>","/home/gretzy/keterangan.txt", NULL};
  execv("/usr/bin/echo", argv);
  }
  else{
    while ((wait(&status)) > 0);
  }
}


void function21111(char token[],char * nama,char * petname,char age[])
{
 pid_t child_id1;
  int status;
  child_id1 = fork();
  if (child_id1 < 0) {
  exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  }
  if (child_id1 == 0) {
  // while ((wait(&status)) > 0);
    // this is childi
    chdir("/home/gretzy/modul2/petshop");
 //  printf("nama:%s\n",filename);
   char *argv[] = {"mv",nama,token, NULL};
   execv("/bin/mv", argv);
  }
  else{
    while ((wait(&status)) > 0);
    function211111(token,nama,petname,age);
   return;
  }
}





void function2111(char token[],char * filename,char * petname,char age[])
{
 pid_t child_id1;
  int status;
  char *nama=strcat(petname,".jpg");
  child_id1 = fork();
  if (child_id1 < 0) {
  exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  }
  if (child_id1 == 0) {
  // while ((wait(&status)) > 0);
    // this is childi
    chdir("/home/gretzy/modul2/petshop");
 //  printf("nama:%s\n",filename);
   char *argv[] = {"mv",filename,nama, NULL};
   execv("/bin/mv", argv);
  }
  else{
    while ((wait(&status)) > 0);
   function21111(token,nama,petname,age);
   return;

  }

}


void function211(char token1[],char * filename,char * petname,char age[])
{

char * token=strtok(token1,";");

 pid_t child_id1;
  int status;

  child_id1 = fork();
//  chdir("/home/gretzy/modul2/petshop");
  if (child_id1 < 0) {
//	return;
  exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  }
  if (child_id1 == 0) {
  // while ((wait(&status)) > 0);

    // this is child
   chdir("/home/gretzy/modul2/petshop");
 // while ((wait(&status)) > 0); 
   printf("nama token:%s\n",token);
    char *argv[] = {"mkdir",token, NULL};
    execv("/bin/mkdir", argv);
 
  
  } else {
    // this is parent
    while ((wait(&status)) > 0);
	function2111(token,filename,petname,age);
    return;
   
  }

}

void function21211111(char * filename,char * folder,char token[],char * nama,char * nama1, char * nama2)
{
  pid_t child_id1;
  int status;
  child_id1 = fork();
  if (child_id1 < 0) {
  exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  }
  else if (child_id1 == 0) {
  // while ((wait(&status)) > 0);

    // this is child
    chdir("/home/gretzy/modul2/petshop");
    char *argv[] = {"mv",strcat(nama1,".jpg"),token, NULL};//belum selesai
    execv("/bin/mv", argv);

  } else {
    // this is parent
    while ((wait(&status)) > 0);
//    function2121111(filename,folder,token,petname,nama1,nama2);
    return;
  }
}



void function2121111(char * filekedua,char * folderkedua,char token[],char * nama, char * nama1, char * nama2)
{
  pid_t child_id1;
  int status; 
printf("folder-=-0=0=  %s, file 8wduwdidw= %s\n",token,nama);
   child_id1 = fork();
  if (child_id1 < 0) {
  exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  }
  if (child_id1 == 0) {
 printf("filekedua=%s...........................%s\n",nama,nama1);
    // this is child
    chdir("/home/gretzy/modul2/petshop");
//    char *argv[] = {"mv",nama,token, NULL};//belum selesai
  //  execv("/bin/mv", argv);
      char *argv[] = {"mv",nama,strcat(nama1,".jpg"), NULL};//belum selesai
      execv("/bin/mv", argv);
  } else {
    // this is parent
    while ((wait(&status)) > 0);
    function21211111(filekedua,folderkedua,token,nama,nama1,nama2);
    return;
  }
}





void  pivot(char * filekedua,char * folderkedua,char token[],char * nama, char * nama1, char * nama2)
{
  pid_t child_id1;
  int status;
printf("folder-=-0=0=  %s, file 8wduwdidw= %s\n",token,nama);
   child_id1 = fork();
  if (child_id1 < 0) {
  exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  }
  if (child_id1 == 0) {
 printf("filekedua=%s...........................%s\n",nama,nama1);
    // this is child
    chdir("/home/gretzy/modul2/petshop");
//    char *argv[] = {"mv",nama,token, NULL};//belum selesai
  //  execv("/bin/mv", argv);
      char *argv[] = {"mv",strcat(nama2,".jpg"),folderkedua, NULL};//belum selesai
      execv("/bin/mv", argv);
  } else {
    // this is parent
    while ((wait(&status)) > 0);
    function2121111(filekedua,folderkedua,token,nama,nama1,nama2);

    return;
  }
}







void function212111(char * filekedua,char * folderkedua,char token[],char * nama,char * nama1, char * nama2)
{
  pid_t child_id1;
  int status;

     
  child_id1 = fork();
//  chdir("/home/gretzy/modul2/petshop");
  if (child_id1 < 0) {
//      return;
  exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  }
  if (child_id1 == 0) {
  // while ((wait(&status)) > 0);

    // this is child
   chdir("/home/gretzy/modul2/petshop");
    char *argv[] = {"mv",filekedua,strcat(nama2,".jpg"), NULL};//belum selesai
    execv("/bin/mv", argv);

  } else {
    // this is parent
    while ((wait(&status)) > 0);
     //  function2121111(filekedua,folderkedua,token,nama,nama1,nama2);
       pivot(filekedua,folderkedua,token,nama,nama1,nama2);
	 return;

  }

}



//akhir
void function21211(char token[],char *token3,char * filename,char * nama, char * nama1,char * nama2)
{
       int panjang=strlen(filename);
       char str[panjang],str1[panjang];
       strcpy(str,filename);
       strcpy(str1,str);
       int add=0;
       char* filekedua=strtok(str1,"_");
       filekedua=strtok(NULL,"_");
printf("strending:%s\nnamafileending=%s\n",str1,filekedua);

 pid_t child_id1;
  int status;
  child_id1 = fork();
  if (child_id1 < 0) {
  exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  }
  if (child_id1 == 0) {
  // while ((wait(&status)) > 0);

   // this is childi
    chdir("/home/gretzy/modul2/petshop");
   char *argv[] = {"mv",filename,filekedua,NULL};//perlu diganti banget
  // char *argv[] = {"mv",filename,token4, NULL};
   execv("/bin/mv", argv);
  }
  else{
    while ((wait(&status)) > 0);
    function212111(filekedua,token3,token,nama,nama1,nama2);
   return;

  }

}







void function2121(char token[],char *token3,char * filename,char * nama1, char * nama2)
{
       int panjang=strlen(filename);
       char str[panjang],str1[panjang];
       strcpy(str,filename);
       strcpy(str1,str);
       int add=0;
       char* token4=strtok(str1,"_");
       token4=strtok(NULL,"_");
printf("strkhusus:%s\ntoken4=%s\n",str1,token4);
char * nama=strcat(str1,".jpg");

 pid_t child_id1;
  int status;
  child_id1 = fork();
  if (child_id1 < 0) {
  exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  }
  if (child_id1 == 0) {
  // while ((wait(&status)) > 0);

   // this is childi
    chdir("/home/gretzy/modul2/petshop");
   char *argv[] = {"cp",filename,nama, NULL};//diubah
   execv("/bin/cp", argv);
  }
  else{
    while ((wait(&status)) > 0);
    function21211(token,token3,filename,nama,nama1,nama2);
   return;

  }

}



void function212(char token1[],char *token3,char * filename,char * nama1,char * nama2)
{

char * token=strtok(token1,";");

 pid_t child_id1;
  int status;

  child_id1 = fork();
//  chdir("/home/gretzy/modul2/petshop");
  if (child_id1 < 0) {
//      return;
  exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  }
  if (child_id1 == 0) {
  // while ((wait(&status)) > 0);

    // this is child
   chdir("/home/gretzy/modul2/petshop");
 // while ((wait(&status)) > 0); 
   printf("nama token:%s\n",token);
    char *argv[] = {"mkdir",token, NULL};
    execv("/bin/mkdir", argv);
  } else {
    // this is parent
    while ((wait(&status)) > 0);
       function2121 (token1,token3,filename,nama1,nama2);
    return;

  }

}

void function21()
{ 
printf("bisa\n");
FILE *fp;
  DIR *d;
  struct dirent *dir;
  char *filenames[15];
  //char *filenames = malloc(sizeof *filenames);
  int i=0;
  int a;
  // function1();
  d = opendir("/home/gretzy/modul2/petshop");
	printf("sukses");
  if (d)
  {
    while ((dir = readdir(d)) != NULL)
    {
           
     filenames[i]=(dir->d_name);
     int panjang=strlen(filenames[i]);
       printf("nama file=%s\npanjang=%d",filenames[i],panjang);
     
       char str[panjang],str1[panjang];
       strcpy(str,filenames[i]);
       strcpy(str1,str);
       int add=0;      
       char* token=strtok(str1,";");
       char* token1[8];
    
       while(token!=NULL){
//		printf("token:%s\n",token);
		token=strtok(NULL,";");
                token1[add]=token;
		printf("token %d =%s\n",add,token1[add]);
		add++;
	}
	   printf("jumlah token=%d\n",add);
      

	if(add==3){

	function211(str1,filenames[i],token1[0],token1[1]);
	}
      else{

	int lenght=strlen(token1[1]);
       char str2[lenght],str3[lenght];
       strcpy(str2,token1[1]);
       strcpy(str3,str2);
       char* token3=strtok(str3,"_");
       token3=strtok(NULL,"_");
	printf("token khusus %s\n",token3);
	
/*

	int agelen1=strlen(token1[2]);
        char age1[agelen1];
        strcpy(age1,token1[2]);
        age1[agelen1-1]=' ';
         age1[agelen1-2]=' ';
      age1[agelen1-3]=' ';
     age1[agelen1-4]=' ';

     char folder1[]="/home/gretzy/modul2/petshop/";
     char namafile1[]="//home/gretzy/.txt";
     strcat(folder1,str1);
      chdir(folder1);


        FILE *f = fopen("/home/gretzy/.txt","a");
        fprintf(f,"Nama:%s\nUmur:%s\n",token1[2],age1);
        fclose(f);
*/
        function212(str1,token3,filenames[i],token1[0],token1[2]);      
  
    }



 
      printf("str1:%s\n",str1);
      

      printf("%s",*(char**)&filenames[i]);
      printf("\n\n\n`");
      i++;
      
    }
    printf("\n");
    closedir(d);
  }
}

void function2(){

int status;
pid_t child_id1;

child_id1=fork();
if (child_id1 < 0) {
  exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  }

  if (child_id1 == 0) {
   // execlp("ls","ls",NULL);
	function21();
  } else {
    while ((wait(&status)) > 0);
    function21();
      //  execlp("ls","ls", NULL);
	

  }


}

int main(){

int status;
pid_t child_id1;

child_id1=fork();
if (child_id1 < 0) {
//  exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  }

  if (child_id1 == 0) {
    function1();
  } else {
    while ((wait(&status)) > 0);
    function2();
  }


}

