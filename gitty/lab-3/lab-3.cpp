//TO do list function 
#include<iostream>

class list{
    private :
    int cur=0;
    int lim=5;
    int arr[5];

    public:
        void display();// To print the array

        int insert_beg(int num);//To insert in the begining

        int insert_end(int num);//To insert in the end

        int insert_mid(int num,int index);//To insert in the index

        int del_beg();//To delete the first number

        int del_end();//To delete the last number

        int del_pos(int index);//To delete the number form the given index

        int search(int num);//To search the number and return the index

        int rotate(int k);//To rotate the array towards right
    

};

int main(){
    list array;
    int choice,ans,num,index,k;
    while(true){
    printf("\nMENU : \n 1)Insert Beginning \n 2)Insert End \n 3)Insert position \n 4)Delete Begining \n 5)Delete End \n 6)Delete Position \n 7)Search \n 8)Display \n 9)Rotate \n 10)Exit \n");
    printf("Enter the choise : ");
    scanf("%d",&choice);
    switch (choice){
        case 1:
        printf("Enter the number to be inserted : ");
        scanf("%d",&num);
        ans=array.insert_beg(num);
        if(ans==0){
            printf("Out of storage !!");
        }
        break;

        case 2:
        printf("Enter the number to be inserted : ");
        scanf("%d",&num);
        ans=array.insert_end(num);
        if(ans==0){
            printf("Out of storage !!");
        }
        break;
        
        case 3:
        printf("Enter the index to be inserted : ");
        scanf("%d",&index);
        printf("Enter the number to be inserted : ");
        scanf("%d",&num);
        ans=array.insert_mid(num,index);
        if(ans==0){
            printf("Out of storage !!");
        }
        if(ans==(-1)){
            printf("Invalid index");
        }
        break;

        case 4:
        ans=array.del_beg();
        if(ans==0){
            printf("Empty array !!");
        }
        break;

        case 5:
        ans=array.del_end();
        if(ans==0){
            printf("Empty array !!");
        }
        break;

        case 6:
        printf("Enter the index to be inserted : ");
        scanf("%d",&index);
        ans=array.del_pos(index);
        if(ans==(-1)){
            printf("Invalid index");
        }
        if(ans==0){
            printf("Empty array !!");
        }
        break;

        case 7:
        printf("Enter the number to be searched : ");
        scanf("%d",&num);
        ans=array.search(num);
        if(ans==(-1)){
            printf("Invalid num");
        }
        else{
            printf("Your number's index is %d",ans);
        }
        break;


        case 8:
        array.display();
        break;

        case 9:
        printf("Enter the number of times to be rotated : ");
        scanf("%d",&k);
        ans=array.rotate(k);
        if(ans==(1)){
            printf("Rotated %d times",k);
        }
        break;

        case 10:
        printf("Exiting the loop !!\n");
        break;

        default:
        printf("You have entered a wrong value !!\n");
        
    }
    if(choice==10){
        break;
    }
    else{
        continue;
    }
    }
}

void list::display(){
        for(int i=0;i<cur;i++){
            printf("%d  ",arr[i]);
        }
        printf("\n");

        }

int list::insert_beg(int num){
        if(cur>=5){
            return 0;
        }
        for(int i=cur;i>=0;i--){
            arr[i]=arr[i-1];
        }
        arr[0]=num;
        cur++;
        return 1;
    }

int list::insert_end(int num){
        if(cur>=5){
            return 0;
        }
        arr[cur]=num;
        cur++;
        return 1;
    }

int list::insert_mid(int num,int index){
        if(cur>=5){
            return 0;
        }
        if(index<0 || index>lim){
            return -1;
        }
        for(int i=cur;i>index;i--){
            arr[i]=arr[i-1];
        }
        arr[index]=num;
        cur++;
        return 1;
    }

int list::del_beg(){
    if(cur<=0){
            return 0;
        }
        for(int i=0;i<(cur-1);i++){
            arr[i]=arr[i+1];
        }
        cur--;
        return 1;
    }

int list::del_end(){
    if(cur<=0){
            return 0;
        }
    cur--;
    return 1;
    }


int list::del_pos(int index){
    if(cur<=0){
            return 0;
        }
        if(index<0 || index>lim){
            return -1;
        }
        for(int i=index;i<(cur-1);i++){
            arr[i]=arr[i+1];
        }
        cur--;
        return 1;
    }

int list::search(int num){
        for(int i=0;i<cur;i++){
            if(arr[i]==num){
            return i;
            }
        }
        return -1;
    }

int list::rotate(int k){
        int temp=0;
        for(int i=0;i<k;i++){
            temp=arr[0];
            for(int j=0;j<(cur-1);j++){
                arr[j]=arr[j+1];

            }
            arr[cur-1]=temp;
        }
        return 1;
    }
