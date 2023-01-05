#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define LINE 256
#define WORD 30



void Text();
int getsizeline(char s[]);
int getLine(char s[]);
int getWord(char w[]);
int substring( char * str1, char * str2);
int similar (char *s, char *t, int n);
void print_lines(char *str,char *text);
void print_similar_words(char *str,char *text);


void Text(char *text){
   char temp = ' ';
   int i = 0;
   while(scanf("%c",&temp) != EOF){
        text[i] = temp;
        i++;
   }

    text[i]= '\0';
}
int getsizeline(char s[]){
    int count =0;
    for ( int i=0 ; i < strlen(s); i++)
     {
        if(s[i] == '\n'){
            count++;
        }
     }
     return count;
}
int getLine(char s[]){
    
    int i=0;
    for (  i ; i < strlen(s); i++)
        {
            if(s[i] == '\n'){
                break;
            }

        }
            
return i;
}

int getWord(char w[]){
    int i=0;
    
    for ( i ; i < WORD; i++)
    {
        if(w[i] == '\n' ||w[i] == '\t' || w[i] == ' '){
            break;
        }
    }
return i;
}
int substring( char * str1, char * str2){
  
    int count = 0;
    int size_str1 = strlen(str1);
    int size_str2 = strlen(str2);
    int y=0;
    if(size_str2 > size_str1)return 0;

    for (int i = 0; i < size_str1; i++)
    {
       
        if (str1[i] == str2[y])
        {
            count++;
            y++;
            if(count == size_str2)return 1;

        }
        else{
            y=0;
            count = 0;
        }
       
    }

    return 0;
}

int similar (char *s, char *t, int n){
    int count = 0,y=0;
    int sLenght = strlen(s);
    int tLenght = strlen(t);
    if(sLenght<tLenght)return 0;
    if(sLenght-tLenght > n)return 0;
    for (int i = 0; i <sLenght && y<tLenght ; i++)
    {       
            if(s[i] != t[y]){
                count++;
            }else{
                y++;
            }
            if (count > n)
            {
                return 0;
            }  
    }
     if (count <= n)
        {
            return 1;
        }
    return 0;
}


void print_lines(char *str , char *text){

    int count_of_Line = getsizeline(text);
    int size_line = 7;
    int start_line = 7;
    char temp[LINE];
    int o=0,b;
    memset(temp,0,LINE);
  
    for (int i = 2; i < count_of_Line; i++)
    {  
      
        size_line = start_line +getLine(text + start_line)+1;
       
        for ( b = start_line; b < size_line; b++,o++)
        {
            temp[o] = text[b];      
        }
   
        if(substring(temp,str) == 1){

            for (int j = start_line;j < size_line;j++)
            {
                printf("%c",text[j]);
            }
        }
         start_line =  size_line;
         o=0;
          memset(temp,0,LINE);
    }
    
       
   
}

void print_similar_words(char *str, char *text){

    int sizeWord =0;
    int tempSizeWord=6;
    char tempWord[WORD];
    int y=0;
   
    while(tempSizeWord < strlen(text)){
        
        sizeWord = getWord(text+tempSizeWord);
        for (int i = 0+tempSizeWord; i < sizeWord+tempSizeWord; i++,y++)
        {
            tempWord[y]=text[i];
        }
         y=0;
       

        if(similar(tempWord,str,1) == 1){
            for (int j = 0; j < strlen(tempWord); j++)
            {
                printf("%c",tempWord[j]);
            }
            printf("\n");
            
        }
       
        tempSizeWord = 1+tempSizeWord+  sizeWord;
        memset(tempWord, 0, sizeof(tempWord));

    }

}

int main(){

    char text[LINE]=" ";
    
    Text(text);
    
  
    int cfunc = getWord(text)+1;
    char t[cfunc-1];
    memset( t, 0, (cfunc-1)*(cfunc-1)*sizeof(char) );
    for (int i = 0; i < getWord(text); i++)
    {
        t[i] = text[i];
    }
    
    char f = text[cfunc];
    
    if(f == 'a'){
        print_lines(t,text);
    }
    else if (f == 'b'){
        print_similar_words(t,text);
    }

   
return 0;
}
