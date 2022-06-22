
#include"parse.h"

int main(int argc,char** argv){

if(argc==2){

    printRIDxPIXsort(argv[argc-1]);

}else if(argc<2){
    printf("Error: Need more args\n");
}else{
    printf("Error: Many args\n");
}


}