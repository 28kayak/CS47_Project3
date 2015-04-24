// This is the main project file for VC++ application project 
// generated using an Application Wizard.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>

int b_search (char list[100][20], int count, char* token)
{
__asm
{
	mov eax, 0			; zero out the result
	mov esi, list		; move the list pointer to ESI
	mov edi, token		; move the token to ebs
	mov ecx, 0			; move the ecx to the bottom of list index
	mov edx, count		; move count to ebx
	sub edx, 1			;subtract one from edx to point the last index in the list
	mov ebx, edx		;set ebx to be middle
	shr ebx, 1			;divide by 2 to take mean
	imul ebx, 20		;multiply by 20which the size of char array 
	push ecx			;push the last index into the stack
	push edx			; push the first index into the stack
	mov edx, 0			;swich edx to be the index of the given array
	; done setting up variables we need.
compchar:	;compare strings ofchars 
	mov eax, esi		;set a pointer eax to the first index of the list
	add eax, ebx		;move eax ptr to right string 
	mov eax,[eax + ebx] ;move eax ptr to right char 
	mov ecx,[edi + edx] ;point ecx to right char ofthe given token
	add edx, 1			;edx++ to reffer the next idex
	cmp cl, '\0'		;determine if the index reaches to the END token
	je tokenChecked     ;if it reaches, jump to tokenChecked
	cmp al, '\0'		;determine if the index reaches to the end of the given list
	je adjestPointers 	;if true, jump to adj	
	
	or cl, 0x20			;convert chars in cl to lower
	or al, 0x20			;convert chars in al to lower
	cmp cl, al			;compare one char in cl and the other in al at time 
	je compchar         ;jump to comp ture if previous condition is true
adjestPointers:
	sub al, cl			;cl - al

	pop edx;			;pop up edx that previously pushed
	pop ecx;			;pop up ecx that preciously pushed

	mov ebx, edx		;calcualate new mid point 
	add ebx, ecx		;
	shr ebx, 1			;

	cmp al, 0			;
	jl bottom			;
	mov edx, ebx		;
	sub edx, 1			;
	jmp adjestPointer2	;
bottom:;
	mov ecx,ebx; set the bottom to the top index
	add ecx, 1; add one 
adjestPointer2:;
	cmp edx, ecx; compthe first index and the last index
	jl notFound;

	mov ebx, edx		;
	add ebx, ecx		;caluclate new middle
	shr ebx, 1			;
	imul ebx, 20		;

	push ecx;
	push edx;

	mov edx, 0			;edx to be zero
	jmp compchar		;
tokenChecked: ;
	cmp al, '\0'		;check if al in eax reaches to the end
	jne adjestPointers
found:					;token is in the list 
	mov eax, ebx		;move ebx = mid point to eax 
	mov ebx, 20			;
	mov edx, 0			;
	idiv ebx			;divide by ebx = 20 
	mov ebx, 0			;ebx to be zero
	pop ecx				;clear the stack
	pop edx				;clear the stack
	add eax,1			;to have consistency on starting index value 
	jmp done			;jump to done 
notFound:;
	mov eax, 0			;set the result to be zero
done:					;finished!
















	















						

}

}

int main(int argc, char** argv)
{
	char list[100][20], *token;
	FILE *fptr;
	int id = 0;
	int i = 0;
	
	if (argc != 3)
	{
		printf("Usage: %s filename token\n", argv[0]);
		return 1;
	}

	token = argv[2];

	printf("\n");

	fptr = fopen((argv[1]), "rtc");
	if (fptr == NULL)
      printf( "File %s was not opened\n",argv[1] );
	else
   {
      /* Set pointer to beginning of file: */
      //fseek( fptr, 0L, SEEK_SET );

      /* Read data from file: */
	  
	  while ( fscanf(fptr, "%s", &list[i]) != EOF )
	  {
          printf( "%s ", list[i] );
		  i++;
	  }

      printf( "\n\nNumber of names = %d\n", i );
      printf( "Search Token = %s\n", token );
      fclose( fptr );

   }
   
	
   id = b_search( list, i, token);

   if (id)
	   printf( "Search token is in the number %d position.\n", id );
   else
     printf( "Search token is not found.\n");

   return 0;
}



	