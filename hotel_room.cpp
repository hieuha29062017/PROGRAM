#include<stdio.h>


int Number_Room[1000];
int Count = 0;
void Read_Data(char* namefile){
    int i = 0;
    FILE* f = fopen(namefile,"r");
    while(1){
        int temp;
        fscanf(f,"%d",&temp);
        if(temp == -1) break;
        Number_Room[i] = temp;
        i++;
        Count++;
    }
    fclose(f);
}
//============================
void Solve(int a[], int Count){
    int i,Min,Max;
    for(i=0; i<Count; i++){
        if((a[i+1] - a[i] == 1) && (a[i+2]-a[i] == 2)){
            Min = a[i];
            while(a[i+1] - a[i] == 1)
                i++;
            Max = a[i];
        if(i == Count - 1)
            printf("%d - %d",Min,Max);
        else
            printf("%d - %d,",Min,Max);
        }
        else{
            if(i == Count - 1)
                printf("%d",a[i]);
            else
                printf("%d,",a[i]);
        }
    }
}
int main(){
    Read_Data("room.txt");
    /*int i;
    for(i = 0; i<Count; i++){
        printf("%5d", Number_Room[i]);
    }*/
    Solve(Number_Room,Count);
}
