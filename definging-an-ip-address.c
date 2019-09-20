//title num:1108

#include <stdio.h>
#include <stdlib.h>

char * defangIPaddr(char * address)
{
    char *ptr = calloc(100, sizeof(char));
    char *head_ptr=ptr;
    while(*address)
    {
        if(*address == '.')
        {
            *ptr++ = '[';
            *ptr++ = '.';
            *ptr++ = ']';
            address++;
            continue;
        }
        *ptr++ = *address++;
    }
   return head_ptr; 
}

int main()
{
    printf("%s\n", defangIPaddr("12.34.56.78"));
    /*
    char aaa[5]="1234", *aa=aaa;
    printf("%c\n", *aa); //1
    *aa++ = 'a';
    printf("%c\n", *aa); //2
    printf("%s\n", aaa); //a234
    char bbb[5]="1234";
    aa=bbb;
    printf("%c\n", *aa); //1
    *(++aa) = 'a';
    printf("%c\n", *aa); //a
    printf("%s\n", bbb); //1a34
    */
    return 0;
}
