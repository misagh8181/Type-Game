#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "helper_windows.h"
#include <stdlib.h>
#include <unistd.h>
int i,j,n,m,l,o=0,shomaresh_gar=0,fasele=0,sathe_bazi,tedad_characterha,tedad_kalame,time,moje=1,emtiaz=0,shomaresh_moje=1;
int kalame_sookhteh[100];
int mobham[100];
int mamooli[100];
int yakhi[100];
struct kalameha{ 
  char kalame[20];
  int chek[20];
};
struct kalameha Kalameha[100];
FILE *stream;
int x=0,y=0;
/*to har moje 3 kalame mamooli , 2 kalame boland , 1 kalame sakht , 3 kalame mobham ,1 kalame yakhi*/



void my_callback_on_key_arrival(char c){
  if(c==Kalameha[y].kalame[x]){
    Kalameha[y].chek[x]=2;
    x++;
  }
  if(Kalameha[y].kalame[x]==0){
    x=0;
    y++;
  }
  if(Kalameha[y].kalame[x]==42){
    x++;
  }
  // Do something with this c>>this c shows azzci code of letters
}



int main(){
  system("CLS");
  printf("#   1.Easy   #\n#  2.Normal  #\n#   3.Hard   #\nsathe bazi (1 or 2 or 3) (^_^) :");
  scanf("%d",&sathe_bazi);
  if(sathe_bazi==1) time=10;
  if(sathe_bazi==2) time=8;
  if(sathe_bazi==3) time=5;
  system("CLS");
  // Menu stuff goes here
  HANDLE thread_id = start_listening(my_callback_on_key_arrival);
  // The rest of your main code goes here
  //dar halat adi mobham nistan
  for(i=0;i<100;i++){
    mobham[i]=1;
  }
  //dar halat adi mamooli hastan
  for(i=0;i<100;i++){
    mamooli[i]=1;
  }
  //dar halat adi yakhi nistan
  for(i=0;i<100;i++){
    yakhi[i]=1;
  }
  stream=fopen("kalameha.txt","r");
  for(m=0,tedad_kalame=1;(fscanf(stream,"%s",Kalameha[m].kalame))!=EOF;m++,tedad_kalame++){
    system("CLS");
    fasele=0;
    if(tedad_kalame%11==0){ 
      if(sathe_bazi==1){ 
        time=time*0.8;
        if(time<=1){
          time=1;
        }
      }
      if(sathe_bazi==2){ 
        time=time*0.7;
        if(time<=1){
          time=1;
        }
      }
      if(sathe_bazi==3){ 
        time=time*0.6;
        if(time<=1){
          time=1;
        }
      }
    }
    if(tedad_kalame%10==0){
      printf("\033[0;31m");
      printf("#       moje  badi       #\n");
      printf("\033[0m");
      fasele=1;
    }
    int u;
    for(u=0;Kalameha[m].kalame[u]!=0;u++){
      Kalameha[m].chek[u]=1;
    }
    for(i=0;Kalameha[m].kalame[i]!=0;i++){
      if(Kalameha[m].kalame[i]==42){
        mobham[m]=2;
        break;
      }
    }
    //chap shodan n ta kalema avalemoon be soorat char be char va chek kardan sookhte boodan kalamat(az n ta avali)
    int g;
    g=-1;
    for(n=m;n>g;n--){
      //chek kardan sookhte boodan kalamat 
      g=-1;
      int z,k;
      for(z=0;z<=n;z++){
        if(mobham[z]==2){
          for(k=1;Kalameha[z].kalame[k]!=0;k++){
            kalame_sookhteh[z]=2;
            if(Kalameha[z].chek[k]!=2){
              kalame_sookhteh[z]=1;
              break;
            }
          }
          if(kalame_sookhteh[z]==2) g++;
        }
        if(mobham[z]==1){
          for(k=0;Kalameha[z].kalame[k]!=0;k++){
            kalame_sookhteh[z]=2;
            if(Kalameha[z].chek[k]!=2){
              kalame_sookhteh[z]=1;
              break;
            }
          }
          if(kalame_sookhteh[z]==2) g++;
        }
      }
      //payan chek kardan sookhte boodan kalamat
      //emtiaz dehi
      if(g>=0){
        if(o==g){
          for(k=0;Kalameha[o].kalame[k]!=0;k++){
            if(mobham[o]==1){
              if(Kalameha[o].kalame[k]==35){
                mamooli[o]=2;
                yakhi[o]=2;
                time=time*3;
                break;
              }
              if(Kalameha[o].kalame[k]==95){
                for(i=0;Kalameha[o].kalame[i]!=0;i++){
                  if(Kalameha[o].kalame[i]==35){
                    mamooli[o]=2;
                    yakhi[o]=2;
                    break;
                  }
                }
                if(yakhi[o]==2){
                  time=time*3;
                  break;
                }
                mamooli[o]=2;
                emtiaz=emtiaz+2;
                break;
              }
              if(Kalameha[o].kalame[k]==64||Kalameha[o].kalame[k]==36||Kalameha[o].kalame[k]==37||Kalameha[o].kalame[k]==94||Kalameha[o].kalame[k]==38||Kalameha[o].kalame[k]==33){
                for(i=0;Kalameha[o].kalame[i]!=0;i++){
                  if(Kalameha[o].kalame[i]==35){
                    mamooli[o]=2;
                    yakhi[o]=2;
                    break;
                  }
                }
                if(yakhi[o]==2){
                  time=time*3;
                  break;
                }
                mamooli[o]=2;
                emtiaz=emtiaz+3;
                break;
              }
            }
            if(mobham[o]==2){
              if(Kalameha[o].kalame[k]==95){
                mamooli[o]=2;
                emtiaz=emtiaz+3;
                break;
              }
              if(Kalameha[o].kalame[k]==64||Kalameha[o].kalame[k]==36||Kalameha[o].kalame[k]==37||Kalameha[o].kalame[k]==94||Kalameha[o].kalame[k]==38||Kalameha[o].kalame[k]==33){
                mamooli[o]=2;
                emtiaz=emtiaz+4;
                break;
              }
            }
          }
          if(mobham[o]==1){
            if(mamooli[o]==1) emtiaz=emtiaz+1;
          }
          if(mobham[o]==2){
            if(mamooli[o]==1) emtiaz=emtiaz+2;
          }
          o++;
        }
      }
      //payan emtiaz dehi
      //shomaresh moje ha
      if(g>0){
        if(shomaresh_moje==g){
          if(shomaresh_moje%9==0){
            moje++;
          }
          shomaresh_moje++;
        }
      }
      //payan shomaresh moje ha
      for(tedad_characterha=0;Kalameha[n].kalame[tedad_characterha]!=0;tedad_characterha++);
      i=(24-tedad_characterha)/2;
      j=i;
      printf("#");
      for(i;i>0;i--){
        printf(" ");
      }
      if(mobham[n]==1){
        for(i=0;i<tedad_characterha;){
          if(Kalameha[n].chek[i]==1){
            printf("%c",Kalameha[n].kalame[i]);
            i++;
          }
          if(Kalameha[n].chek[i]==2){
            printf("\033[0;31m");
            printf("%c",Kalameha[n].kalame[i]);
            printf("\033[0m");
            i++;
          }
        }
      }
      if(mobham[n]==2){
        if(y==n){
          for(i=1;i<tedad_characterha;){
            if(Kalameha[n].chek[i]==1){
              printf("%c",Kalameha[n].kalame[i]);
              i++;
            }
            if(Kalameha[n].chek[i]==2){
              printf("\033[0;31m");
              printf("%c",Kalameha[n].kalame[i]);
              printf("\033[0m");
              i++;
            }
          }
        }
        else{
          for(i=1;i<tedad_characterha;i++){
            printf("*");
          }
        }
        j=j+2;
      }
      for(j;j>0;j--){
        printf(" ");
      }
      printf("#\n");
    }
    //payan chap shodan n ta kalema avalemoon be soorat char be char va chek kardan sookhte boodan kalamat
    //tedad kalamei ke chap mishe be joze sookhte ha
    l=m-g;
    //payan tedad kalamei ke chap mishe be joze sookhte ha
    u=l+fasele;
    for(n=0;n<(20-(u+1));n++){
      printf("#                        #\n");
    }
    if((20-(u+1))==0||(20-(u+1))<0){
      system("CLS");
      printf("\033[0;31m");
      printf("you lose!! :(\n");
      printf("\033[0m");
      printf("moje:%d\n",moje);
      printf("your score:%d\n",emtiaz);
      printf("sathe bazi (1.Easy or 2.Normal or 3.Hard) :%d\n",sathe_bazi);
      sleep(5);
      return 0;
    }

    
    

    printf("##########################\n");
    printf("your score:%d",emtiaz);
    sleep(time);
    if(g>=0){
      if(shomaresh_gar==g){
        if(yakhi[shomaresh_gar]==1){
          shomaresh_gar++;
        }
        if(yakhi[shomaresh_gar]==2){
          time=time/3;
          shomaresh_gar++;
        }
      }
    }
  }
  if(m==99){
    system("CLS");
    printf("your tiping is good ;) ");
    printf("your score:%d\n",emtiaz);
    sleep(5);
  }
  fclose(stream);
  WaitForSingleObject(thread_id, INFINITE);
  return 0;
}