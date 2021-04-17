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
//execlp("unzip","unzip","-j","pets.zip","-i","*.jpg","-d","/home/fiansyah/modul2/petshop",NULL);

void function1(){
  pid_t child_id;
  int status;

  child_id = fork();
  
  if (child_id < 0) {
    exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
	
  }

  if (child_id == 0) {
    // this is child
    
    char *argv[] = {"mkdir","/home/fiansyah/modul2/", NULL};
    execv("/bin/mkdir", argv);
    
  } else {
 
    // this is parent
    while ((wait(&status)) > 0);
   execlp("unzip","unzip","-j","pets.zip","-i","*.jpg","-d","/home/fiansyah/modul2/petshop",NULL);

    
   }
   
}


void function211111(char token[],char * nama,char * petname,char age[])
{

int Lage=strlen(age);
age[Lage-1]=' ';
age[Lage-2]=' ';
age[Lage-3]=' ';
age[Lage-4]=' ';

 pid_t child_id1;
  int status;
  child_id1 = fork();
  if (child_id1 < 0) {
  exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  }
  if (child_id1 == 0) {
  // while ((wait(&status)) > 0);
    // this is childi
    chdir("/home/fiansyah/modul2/petshop");
    chdir(token);
    FILE *fp;
    fp=fopen("keterangan.txt","a");
    fprintf(fp,"Nama:%s\nUmur:%s\n",petname,age);
    fclose(fp);
    
 //  printf("nama:%s\n",filename);
   char *argv[] = {"echo","kete", NULL};
   execv("/bin/echo", argv);
  }
  else{
    while ((wait(&status)) > 0);
   // function211111(token,nama,petname);
   return;
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
    chdir("/home/fiansyah/modul2/petshop");
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
    chdir("/home/fiansyah/modul2/petshop");
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
//  chdir("/home/fiansyah/modul2/petshop");
  if (child_id1 < 0) {
//	return;
  exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  }
  if (child_id1 == 0) {
  // while ((wait(&status)) > 0);

    // this is child
   chdir("/home/fiansyah/modul2/petshop");
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





void ganti(char * filename,char * folder,char token[],char * nama1, char * nama2,char age1[],char age2[])
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
    chdir("/home/fiansyah/modul2/petshop");
    chdir(folder);
    FILE *fp;
    fp=fopen("keterangan.txt","a");
    fprintf(fp,"Nama:%s\nUmur:%c\nNama:%s\nUmur:%s\n",nama1,age1[0],nama2,age2);
    fclose(fp);
     char *argv[] = {"echo","sukses", NULL};
    execv("/bin/echo", argv);


  } else {
    // this is parent
    while ((wait(&status)) > 0);
//    function2121111(filename,folder,token,petname,nama1,nama2);
    return;
  }
}





void function21211111(char * filename,char * folder,char token[],char * nama,char * nama1, char * nama2,char age1[],char age2[])
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
    chdir("/home/fiansyah/modul2/petshop");
    char *argv[] = {"mv",strcat(nama1,".jpg"),token, NULL};//belum selesai
    execv("/bin/mv", argv);
 
  } else {
    // this is parent
    while ((wait(&status)) > 0);
    ganti(filename,folder,token,nama1,nama2,age1,age2);
    return;
  }
}



void function2121111(char * filekedua,char * folderkedua,char token[],char * nama, char * nama1, char * nama2,char age1[],char age2[])
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
    chdir("/home/fiansyah/modul2/petshop");
//    char *argv[] = {"mv",nama,token, NULL};//belum selesai
  //  execv("/bin/mv", argv);
      char *argv[] = {"mv",nama,strcat(nama1,".jpg"), NULL};//belum selesai
      execv("/bin/mv", argv);
  } else {
    // this is parent
    while ((wait(&status)) > 0);
    function21211111(filekedua,folderkedua,token,nama,nama1,nama2,age1,age2);
    return;
  }
}











void function212111(char * filekedua,char * folderkedua,char token[],char * nama,char * nama1, char * nama2,char age1[],char age2[])
{
  pid_t child_id1;
  int status;

     
  child_id1 = fork();
//  chdir("/home/fiansyah/modul2/petshop");
  if (child_id1 < 0) {
//      return;
  exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  }
  if (child_id1 == 0) {
  // while ((wait(&status)) > 0);

    // this is child
   chdir("/home/fiansyah/modul2/petshop");
    char *argv[] = {"mv",filekedua,folderkedua, NULL};//belum selesai
    execv("/bin/mv", argv);

  } else {
    // this is parent
    while ((wait(&status)) > 0);
       function2121111(filekedua,folderkedua,token,nama,nama1,nama2,age1,age2);
    return;

  }

}



//akhir
void function21211(char token[],char *token3,char * filename,char * nama, char * nama1,char * nama2,char age1[],char age2[])
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
    chdir("/home/fiansyah/modul2/petshop");
   char *argv[] = {"mv",filename,filekedua,NULL};//perlu diganti banget
  // char *argv[] = {"mv",filename,token4, NULL};
   execv("/bin/mv", argv);
  }
  else{
    while ((wait(&status)) > 0);
    function212111(filekedua,token3,token,nama,nama1,nama2,age1,age2);
   return;

  }

}







void function2121(char token[],char *token3,char * filename,char * nama1, char * nama2,char age1[],char age2[])
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
    chdir("/home/fiansyah/modul2/petshop");
   char *argv[] = {"cp",filename,nama, NULL};//diubah
   execv("/bin/cp", argv);
  }
  else{
    while ((wait(&status)) > 0);
    function21211(token,token3,filename,nama,nama1,nama2,age1,age2);
   return;

  }

}



void function212(char token1[],char *token3,char * filename,char * nama1,char * nama2,char age1[],char age2[])
{

char * token=strtok(token1,";");

 pid_t child_id1;
  int status;

  child_id1 = fork();
//  chdir("/home/fiansyah/modul2/petshop");
  if (child_id1 < 0) {
//      return;
  exit(EXIT_FAILURE); // Jika gagal membuat proses baru, program akan berhenti
  }
  if (child_id1 == 0) {
  // while ((wait(&status)) > 0);

    // this is child
   chdir("/home/fiansyah/modul2/petshop");
 // while ((wait(&status)) > 0); 
   printf("nama token:%s\n",token);
    char *argv[] = {"mkdir",token, NULL};
    execv("/bin/mkdir", argv);
  } else {
    // this is parent
    while ((wait(&status)) > 0);
       function2121 (token1,token3,filename,nama1,nama2,age1,age2);
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
printf("sayang");
  d = opendir("/home/fiansyah/modul2/petshop");
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
      int panjangtoken1=strlen(token1[1]);
      char tokenpengganti[panjangtoken1];
      strcpy(tokenpengganti,token1[1]);
      function211(str1,filenames[i],token1[0],tokenpengganti);
	}
      else{
	int lenght=strlen(token1[1]);
       char str2[lenght],str3[lenght];
       strcpy(str2,token1[1]);
       strcpy(str3,str2);
       char* token3=strtok(str3,"_");
       token3=strtok(NULL,"_");
	printf("token khusus %s\n",token3);
      int panjangtoken1=strlen(token1[1]);
      char tokenpengganti[panjangtoken1];
      strcpy(tokenpengganti,token1[1]);
        function212(str1,token3,filenames[i],token1[0],token1[2],tokenpengganti,token1[4]);      
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

