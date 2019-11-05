
void __start()
{
    volatile char* tx = (volatile char*) 0x40002000;
    const char* show1 = "*";
    const char* show2 = "=";
    const char* show3 = "\n";
    int ans[10][10];
    int i=0,j=0;
    char k,k1;
    char s,s1;
    char *d;
    int x[2];
    int temp;

    for(i=1;i<10;i++){
        for(j=1;j<10;j++){
                ans[i][j] = i * j;
        }
    }

    for(i=1;i<10;i++){
        for(j=1;j<10;j++){
                x[0]=0;
                x[1]=0;
                temp = ans[i][j];
                while(temp>0){
                        x[1]=temp%10;
                        if((temp/10)>0){
                                temp = temp/10;
                                x[0]=temp%10;
                        }
                        temp = temp/10;
                }


                s = (int) (i+48);
                s1= (int) (j+48);
                d = &s;
                *tx = *d;
                *tx = *show1;

                d = &s1;
                *tx = *d;
                *tx = *show2;

                k = (int) (x[0]+48);
                k1= (int) (x[1]+48);

                d = &k;
                *tx = *d;
                d = &k1;
                *tx = *d;
                *tx = *show3;

        }
    }
}
