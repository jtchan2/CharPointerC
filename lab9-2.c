#include <stdio.h>
#include <string.h>
#define NUM_OF_USERS 10
#define MAX_USER_INPUT_SIZE 100
void addUser(const char* username, const char* password, int* user_count, char creds[2][NUM_OF_USERS][MAX_USER_INPUT_SIZE]){
    char* ptr1= *(*creds+*user_count);
    while(*username!=0){
        *ptr1=*username;
        ptr1++;
        username++;
    }
    char* ptr2= *(*(creds+1)+*user_count);
    *ptr1=0;
    while(*password!=0){
        *ptr2=*password;
        ptr2++;
        password++;
    }
    *ptr2=0;
    
    *user_count+=1;
    
}
int getUserIndex(const char* username, char* creds, int user_count){
    int i=0;
    char* user= creds;
    
    while(i<user_count){
        //printf("%s\n",creds);
        if(strcmp(username,user)==0){
            return i;
        }
        user+=MAX_USER_INPUT_SIZE;
        i++;
        
    }
    return -1;
}
void replaceSecondChar(char new_char, const char* username, int user_count, char creds[2][NUM_OF_USERS][MAX_USER_INPUT_SIZE]){
    int i=0;
    char* ptr1= *(*creds+i);
    while(strcmp(ptr1,username)!=0){
        i++;
        ptr1= *(*creds+i);
    }
    ptr1++;
    *ptr1=new_char;
    ptr1--;
    

}
void printAll(char* creds, int user_count){
    int i=0;
    //user used to get at start of array
    char* user= creds;
    //password gets to part of array that has user1 password by going to part of array that stores passwords i.e. NUMOFUSER*MAXUSERINPUTSIZE
    char* password= creds+(NUM_OF_USERS*MAX_USER_INPUT_SIZE);
    while(i<user_count){
        printf("Username: %s , password: %s\n", user, password);
        //adds MAXUSERINPUTSIZE to go to next space containign another user
        user+=MAX_USER_INPUT_SIZE;
        password+=MAX_USER_INPUT_SIZE;
        i++;
    }
    

}
int main(void){
    char creds[2][NUM_OF_USERS][MAX_USER_INPUT_SIZE];
    int user_count=0;
    addUser("admin", "s#1Pa5", &user_count,creds);
    addUser("vahab", "fgH!12", &user_count,creds);
    replaceSecondChar('@', "vahab", user_count, creds);
    int num= getUserIndex("v@hab",creds[0][0],user_count);
    printf("User is v@hab is found at index %d\n",num);
    printAll(creds[0][0], user_count);
}