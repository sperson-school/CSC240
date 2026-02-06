#include <stdio.h>

int main(){
  int arr[10];
  int count, i;

  printf("Enter a number less than 10: ");
  scanf("%d", &count);

  for(i = 0; i < count; i++){
    printf("Enter an integer: ");
    scanf("%d", &arr[i]);
  }

  printf("Even numbers: \n");
  
  for(i = 0; i < count; i++){
    if(arr[i] % 2 == 0){
      printf("%d", arr[i]);
      printf("\n");
    }
  }
  

  return 0;
}
