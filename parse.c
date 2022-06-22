#include"parse.h"

int priority_cmp(const void * a, const void *b){
    return ((appCard_t*)a)->priority - ((appCard_t*)b)->priority;
}

void printRIDxPIXsort(char* card_answer){
        //supported card
        char suppCard[SUPPCARDLEN][LENHEXBYTE] = {"A0\0","00\0","00\0","06\0","58\0"};

        //hex array
        int sizeHexArr = strlen(card_answer)/2;
        char HexArr[sizeHexArr][LENHEXBYTE];

        //card answer to array
        char* tmpPtrAnswer = card_answer;
    for(size_t i = 0;i<sizeHexArr;++i){

        HexArr[i][0]=*tmpPtrAnswer;
        ++tmpPtrAnswer;
        HexArr[i][1]=*tmpPtrAnswer;
        ++tmpPtrAnswer;
        HexArr[i][2]='\0';

    }

    //check app in answer
    int countApp = 0;
    for(size_t i= 0;i<sizeHexArr;++i){
        if(!strcmp(HexArr[i],APPLICATION_TEMPLATE)){
            ++countApp;
        }
    }

    //check application in answer
    if(countApp==0){

        printf("No application in answer\n");
        return;

    }
    //create array app
    appCard_t appCardArr[countApp];

    int appReadCount = 0;
    int lenAppBit;
    int lenAppId;
    int lenAppPriority;
    int priorityApp;
    bool isCorrectApp = true;

    for(size_t i= 0;i<sizeHexArr;++i){

        if(!strcmp(HexArr[i],APPLICATION_TEMPLATE)){

                appCardArr[appReadCount].isCorrect=false;
                ++i;
                sscanf(HexArr[i], "%x", &lenAppBit);
                ++i;

                while(1){
                    if(!strcmp(HexArr[i],PRIORITY_TEMPLATE)){
                        break;
                    }
                    if(i==sizeHexArr){

                        printf("No priority template\n");
                        break;

                    }
                    ++i;
                }

                ++i;
                sscanf(HexArr[i], "%x", &lenAppPriority);

                while(lenAppPriority!=0){

                    --lenAppPriority;
                    ++i;
                    sscanf(HexArr[i], "%x", &priorityApp);

                }

                int priorityAppEndBit=0;

                for(size_t i = 0;i<4;++i){

                    int bit =(priorityApp>>i)&1;
                    priorityAppEndBit|=bit<<i;

                }
                
                memset(appCardArr[appReadCount].RID,'\0',32);
                memset(appCardArr[appReadCount].PIX,'\0',10);
                appCardArr[appReadCount].priority=priorityAppEndBit;

                while(1){
                    if(!strcmp(HexArr[i],APPLICATIONS)){
                        break;
                    }
                    ++i;
                    if(i==sizeHexArr){

                        printf("No applications");
                        break;

                    }
                }

                ++i;
                sscanf(HexArr[i], "%x", &lenAppId);
                int countIterId = 0;
                int countIterSuppCard=0;

                while(lenAppId!=0){

                    --lenAppId;
                    ++i;

                    if(strcmp(suppCard[countIterSuppCard],HexArr[i])!=0&&countIterSuppCard<5){

                        isCorrectApp=false;
                        appCardArr[appReadCount].isCorrect=false;
                        break;

                    }

                    if(countIterId>=5){

                        strncat(appCardArr[appReadCount].PIX,HexArr[i],2);
                        ++countIterSuppCard;
                        ++countIterId;
                        continue;

                    }

                    strncat(appCardArr[appReadCount].RID,HexArr[i],2);
                    ++countIterSuppCard;
                    ++countIterId;

                    if(isCorrectApp){

                        appCardArr[appReadCount].isCorrect=true;

                }

                }
                isCorrectApp=true;
                ++appReadCount;
        }
    }
    //sort app
    qsort(appCardArr,countApp,sizeof(appCard_t),priority_cmp);

    int cntSuppApp=0;
    //output supported app
    for(size_t i = 0;i<countApp;++i){

        if(appCardArr[i].isCorrect){

                ++cntSuppApp;
            printf("\nRID+PIX: %s%s\n",appCardArr[i].RID,appCardArr[i].PIX);

        }
    }
    if(cntSuppApp==0){

        printf("NO SUPPORTED APP\n");
    
    }

}
