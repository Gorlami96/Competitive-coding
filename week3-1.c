#include <stdio.h>

int main()
{
    long long n;
    scanf("%lld",&n);
    int i,number_of_digits=0;
    long long temp=n;
    while(temp){
        temp=temp/10;
        number_of_digits++;
    }
    int digits[number_of_digits];
    temp=n;
    for(i=0;i<number_of_digits;i++){
        digits[i]=temp%10;
        temp=temp/10;
    }
    for(i=number_of_digits-1;i>=0;i--){
        switch(i){
            case 5:
            if(digits[i]==1){
                printf("One hundred");
            }
            else if(digits[i]==2){
                printf("Two hundred");
            }
            else if(digits[i]==3){
                printf("Three hundred");
            }
            else if(digits[i]==4){
                printf("Four hundred");
            }
            else if(digits[i]==5){
                printf("Five hundred");
            }
            else if(digits[i]==6){
                printf("Six hundred");
            }
            else if(digits[i]==7){
                printf("Seven hundred");
            }
            else if(digits[i]==8){
                printf("Eight hundred");
            }
            else if(digits[i]==9){
                printf("Nine hundred");
            }
            break;
            
            
            case 4:
            if(digits[i]==1){
                i--;
                if(digits[i]==1){
                    printf("eleven thousand");
                }
                else if(digits[i]==2){
                    printf("twelve thousand");
                }
                else if(digits[i]==3){
                    printf("thirteen thousand");
                }
                else if(digits[i]==4){
                    printf("fourteen thousand");
                }
                else if(digits[i]==5){
                    printf("fifteen thousand");
                }
                else if(digits[i]==6){
                    printf("sixteen thousand");
                }
                else if(digits[i]==7){
                    printf("seventeen thousand");
                }
                else if(digits[i]==8){
                    printf("eighteen thousand");
                }
                else if(digits[i]==9){
                    printf("nineteen thousand");
                }
            }
            else if(digits[i]==2){
                printf("twenty");
            }
            else if(digits[i]==3){
                printf("thirty");
            }
            else if(digits[i]==4){
                printf("forty");
            }
            else if(digits[i]==5){
                printf("fifty");
            }
            else if(digits[i]==6){
                printf("sixty");
            }
            else if(digits[i]==7){
                printf("seventy");
            }
            else if(digits[i]==8){
                printf("eighty");
            }
            else if(digits[i]==9){
                printf("ninety");
            }
            break;
            
            
            case 3:
            if(digits[i]==1){
                printf("one thousand");
            }
            else if(digits[i]==2){
                printf("two thousand");
            }
            else if(digits[i]==3){
                printf("three thousand");
            }
            else if(digits[i]==4){
                printf("four thousand");
            }
            else if(digits[i]==5){
                printf("five thousand");
            }
            else if(digits[i]==6){
                printf("six thousand");
            }
            else if(digits[i]==7){
                printf("seven thousand");
            }
            else if(digits[i]==8){
                printf("eight thousand");
            }
            else if(digits[i]==9){
                printf("nine thousand");
            }
            else if(digits[i]==0){
                printf("thousand");
            }
            break;
            
            
            case 2:
            if(digits[i]==1){
                printf("One hundred");
            }
            else if(digits[i]==2){
                printf("Two hundred");
            }
            else if(digits[i]==3){
                printf("Three hundred");
            }
            else if(digits[i]==4){
                printf("Four hundred");
            }
            else if(digits[i]==5){
                printf("Five hundred");
            }
            else if(digits[i]==6){
                printf("Six hundred");
            }
            else if(digits[i]==7){
                printf("Seven hundred");
            }
            else if(digits[i]==8){
                printf("Eight hundred");
            }
            else if(digits[i]==9){
                printf("Nine hundred");
            }
            break;
            
            
            case 1:
            if(digits[i]==1){
                i--;
                if(digits[i]==1){
                    printf("eleven");
                }
                else if(digits[i]==2){
                    printf("twelve");
                }
                else if(digits[i]==3){
                    printf("thirteen");
                }
                else if(digits[i]==4){
                    printf("fourteen");
                }
                else if(digits[i]==5){
                    printf("fifteen");
                }
                else if(digits[i]==6){
                    printf("sixteen");
                }
                else if(digits[i]==7){
                    printf("seventeen");
                }
                else if(digits[i]==8){
                    printf("eighteen");
                }
                else if(digits[i]==9){
                    printf("nineteen");
                }
            }
            else if(digits[i]==2){
                printf("twenty");
            }
            else if(digits[i]==3){
                printf("thirty");
            }
            else if(digits[i]==4){
                printf("forty");
            }
            else if(digits[i]==5){
                printf("fifty");
            }
            else if(digits[i]==6){
                printf("sixty");
            }
            else if(digits[i]==7){
                printf("seventy");
            }
            else if(digits[i]==8){
                printf("eighty");
            }
            else if(digits[i]==9){
                printf("ninety");
            }
            break;
            
            
            case 0:
            if(digits[i]==1){
                printf("one");
            }
            else if(digits[i]==2){
                printf("two");
            }
            else if(digits[i]==3){
                printf("three");
            }
            else if(digits[i]==4){
                printf("four");
            }
            else if(digits[i]==5){
                printf("five");
            }
            else if(digits[i]==6){
                printf("six");
            }
            else if(digits[i]==7){
                printf("seven");
            }
            else if(digits[i]==8){
                printf("eight");
            }
            else if(digits[i]==9){
                printf("nine");
            }
            else if(digits[i]==0){
                printf("thousand");
            }
        }
    }
    return 0;
}