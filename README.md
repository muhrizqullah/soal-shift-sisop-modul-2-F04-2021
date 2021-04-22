# soal-shift-sisop-modul-2-F04-2021

# Anggota Kelompok
- **Thomas Dwi Awaka** (05111940000021)
- **Muhammad Arifiansyah** (05111940000027)
- **Muhammad Rizqullah Akbar** (05111940000178)

# Pembahasan Soal
## Soal 1
#### Kendala
#### Screenshot jalannya progran

## Soal 2
#### Kendala
#### Screenshot jalannya progran

## Soal 3
### Soal 3A
Membuat program C dimana setiap 40 detik membuat sebuah direktori dengan nama sesuai timestamp [YYYY-mm-dd_HH:ii:ss].
```c
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
```
Pada fungsi diatas kita melekakukan spawning process, dimana child process akan melakukan `exec` untuk membuat direktori baru dengan nama sesuai parameter saat fungsi dipanggil di *main*, dan dilakukan sleep di *main* selama 40 detik sesuai yang diminta soal. Lalu pada parent process akan menunggu hingga process di child selesai dan memanggil fungsi `download_img()` untuk mengunduh gambar.
### Soal 3B
Setiap direktori yang sudah dibuat diisi dengan 10 gambar yang diunduh dari link yang diberikan, dimana setiap gambar akan diunduh setiap 5 detik. Setiap gambar juga harus dinamakan sesuai timestamp dan ukurannya ditentukan dengan rumus (n%1000) + 50, diman *n* adalah *detik Epoch UNIX*.
```c
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
```
Sama seperti fungsi sebelumnya akan dilakukan spawning process, dimana pada child process akan dilakukan perpindahan direktori ke yang sudah dibuat di *Soal 3A* . Lalu akan dilakukan looping sebanyak 10 kali untuk mempersiapkan data untuk mengunduh gambar, dimana pada fungsi ini akan ditentukan nama file gambarnya dan linknya dengan ukuran gambar sesuai rumus yang diberikan. untuk mendapatkan *detik Epoch UNIX* menggunakan `time(NULL)`. Kemudian dipanggil fungsi `wget_img()` untuk dilakukan pengunduhan gambar. Lalu pada parent process akan menunggu hingga process pada child selesai kemudian memanggil fungsi `zip_it()` untuk mengkompres direktori.
```c
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

```
Pada fungsi ini digunakan untuk mengeksekusi perintah wget sesuai dengan parameter-parameter yang diberikan pada saat fungsi dipanggil, yaitu link untuk mengunduh foto dan juga nama file.
### Soal 3C
Membuat file *status.txt* dimana di dalamnya berisi pesan *"Download Success"* yang terenkripsi menggunakan metode *Caesar Cipher* yang di shift 5 kali. Lalu akan dizip dan direktorinya akan dihapus.
```c
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
```
Pada fungsi ini akan mengubah string dan dishift sebanyak 5 kali.
```c
        Chyper("Download Success");
        FILE *chy;
        chy = fopen("status.txt", "w");
        fprintf(chy, "%s", pesanChyper);
        fclose(chy);
```
Pada fungsi `download_img()` fungsi `Chyper()` akan dipanggil dan akan memodifikasi string yang diberikan dan menuliskannya ke file *status.txt*.
```c
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
```
Pada fungsi ini akan dilakukan spawning process dan child processnya akan melakukan `exec` untuk mengkompres direktori yang diinginkan menjadi `.zip` dan direktori akan otomatis terhapus.
### Soal 3D dan 3E
```c
FILE *killer;
    killer = fopen("killer.sh", "w");
    if (strcmp(argv[1], "-z") == 0)
    {
        fprintf(killer, "#!/bin/bash\narr=($(ps -aux | grep './soal3' | awk '{ print $2 }'))\nfor i in ${arr[@]}\ndo\nkill -9 $i\ndone\nrm \"$0\"");
    }
    else if (strcmp(argv[1], "-x") == 0)
    {
        fprintf(killer, "#!/bin/bash\narr=($(ps -aux | grep './soal3' | awk '{ print $2 }'))\nkill -9 ${arr[0]}\nrm \"$0\"");
    }
    fclose(killer);

```
Pada baris kode ini akan dibuat file killer.sh untuk menghentikan proses yang ada sesuai dengan argumen yang dipilih.
```bash
#!/bin/bash
arr=($(ps -aux | grep './soal3' | awk '{ print $2 }'))
for i in ${arr[@]}
do
    kill -9 $i
done
rm "$0"
```
Pada saat argumen yang diberikan adalah `-z` maka file *killer.sh* yang dibuat adalah seperti diatas. dimana akan mencari PID terlebih dahulu menggunakan `ps -aux` dan disimpan didalam array. Setelah itu akan dilakukan `kill -9` untuk setiap PID yang didapatkan. Selanjutnya akan menghapus file *killer.sh* menggunakan `rm "$0"`.
```bash
#!/bin/bash
arr=($(ps -aux | grep './soal3' | awk '{ print $2 }'))
kill -9 ${arr[0]}
rm "$0"
```
Pada saat argumen yang diberikan adalah `-x` maka file *killer.sh* yang dibuat adalah seperti diatas. dimana akan mencari PID terlebih dahulu menggunakan `ps -aux` dan disimpan didalam array. Setelah itu akan dilakukan `kill -9` untuk PID pada child process didalam main. Selanjutnya akan menghapus file *killer.sh* menggunakan `rm "$0"`.
#### Kendala

- Kesulitan untuk bisa menunggu program yang sedang berjalan selesai terlebih dahulu.
- Harus melakukan beberapa spawning process untuk bisa membuat file setiap 40 detik dan menyelesaikan saat di`kill`.

#### Screenshot jalannya progran

<img alt="Output Soal3" src="Foto/soal3.png">