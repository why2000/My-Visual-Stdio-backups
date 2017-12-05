//#define NOW
#ifdef NOW
#ifndef _READ_C
#define _READ_C
#include <main.h>
extern evening_struct training[5000];
extern evening_struct testing[5000];
extern total_training_nums;
extern total_testing_nums;
void read_training_data(char* trainingpath) {
    FILE* singlefile;
    char buf[MAX_PATH];
    int place = 0;
    for (int num = 0; num <= 9; num++) {
        strcpy(buf, trainingpath);
        strcat(buf, "\\");
        char foo[2];
        foo[0] = num + 48;
        foo[1] = '\0';
        strcat(buf, foo);
        strcat(buf, "_");
        for (int tens = 0; tens <= 9; tens++) {
            char buf1[MAX_PATH];
            strcpy(buf1, buf);
            char foo[2];
            foo[0] = tens + 48;
            foo[1] = '\0';
            strcat(buf1, foo);
            for (int sing = 0; sing <= 20; sing++) {
                if (sing == 10) {//一位数序号
                    char buf2[MAX_PATH];
                    strcpy(buf2, buf1);
                    strcat(buf2, ".txt");
                    if ((singlefile = fopen(buf2, "r")) == NULL)
                    {
                        continue;//没有的不读
                    }
                    fclose(singlefile);
                    training[place].truelabel = num;
                    training[place].guesslabel = num;
                    training[place].num = place;
                    read_a_single_file(buf2, &training[place]);
                    place++;
                }
                else if (sing >= 11 ) {//三位数序号
                    if (tens == 1||tens ==2) {
                        char buf2[MAX_PATH];
                        strcpy(buf2, buf1);
                        char foo[2];
                        foo[0] = sing-11 + 48;
                        foo[1] = '\0';
                        strcat(buf2, foo);
                        for (int extra = 0; extra <= 9; extra++) {
                            char buf3[MAX_PATH];
                            char foo[2];
                            strcpy(buf3, buf2);

                            foo[0] = extra + 48;
                            foo[1] = '\0';
                            strcat(buf3, foo);
                            strcat(buf3, ".txt");
                            if ((singlefile = fopen(buf3, "r")) == NULL)
                            {
                                continue;//没有的不读
                            }
                            fclose(singlefile);
                            training[place].truelabel = num;
                            training[place].guesslabel = num;
                            training[place].num = place;
                            read_a_single_file(buf3, &training[place]);
                            place++;
                        }
                    }
                }
                else {//两位数序号
                    char buf2[MAX_PATH];
                    strcpy(buf2, buf1);
                    char foo[2];
                    foo[0] = sing + 48;
                    foo[1] = '\0';
                    strcat(buf2, foo);
                    strcat(buf2, ".txt");
                    if ((singlefile = fopen(buf2, "r")) == NULL)
                    {
                        continue;//没有的不读
                    }
                    fclose(singlefile);
                    training[place].truelabel = num;
                    training[place].guesslabel = num;
                    training[place].num = place;
                    read_a_single_file(buf2, &training[place]);
                    place++;
                }
                
                
            }
            
        }
    }
    total_training_nums = place;

}

void read_testing_data(char* testingpath) {
    FILE* singlefile;
    char buf[MAX_PATH];
    int place = 0;
    for (int num = 0; num <= 9; num++) {
        strcpy(buf, testingpath);
        strcat(buf, "\\");
        char foo[2];
        foo[0] = num + 48;
        foo[1] = '\0';
        strcat(buf, foo);
        strcat(buf, "_");
        for (int tens = 0; tens <= 9; tens++) {
            char buf1[MAX_PATH];
            strcpy(buf1, buf);
            char foo[2];
            foo[0] = tens + 48;
            foo[1] = '\0';
            strcat(buf1, foo);
            for (int sing = 0; sing <= 10; sing++) {
                if (sing == 10) {
                    char buf2[MAX_PATH];
                    strcpy(buf2, buf1);
                    char foo[2];
                    strcat(buf2, ".txt");
                    if ((singlefile = fopen(buf2, "r")) == NULL)
                    {
                        continue;//没有的不读
                    }
                    fclose(singlefile);
                    testing[place].truelabel = num;
                    testing[place].num = place;
                    read_a_single_file(buf2, &testing[place]);
                }
                else {
                    char buf2[MAX_PATH];
                    strcpy(buf2, buf1);
                    char foo[2];
                    foo[0] = sing + 48;
                    foo[1] = '\0';
                    strcat(buf2, foo);
                    strcat(buf2, ".txt");
                    if ((singlefile = fopen(buf2, "r")) == NULL)
                    {
                        continue;//没有的不读
                    }
                    fclose(singlefile);
                    testing[place].truelabel = num;
                    testing[place].num = place;
                    read_a_single_file(buf2, &testing[place]);
                }
                place++;
            }
        }
    }
    total_testing_nums = place;

}

void read_a_single_file(char *f_path, evening_struct *file_struct) {
    FILE* reading;
    reading = fopen(f_path, "r+");
    char buf[MAX_LINE];
    int line = 0, raw = 0;
    //这里数据的储存可以用一维数组通过hash算法优化，有时间再改。。。。
    while (fgets(buf, MAX_LINE, reading) != NULL) {
        raw = 0;
        for (int i = 0; buf[i] == '0' || buf[i] == '1'; i++, raw++) {
            file_struct->place[line][raw] = buf[i] - 48;
        }
        line++;
    }

    fclose(reading);
}

int read_file_list(char *path) {
    int nums = 0;
    char buf[MAX_LINE];
    FILE* list;
    FILE* command;
    int len;
    char sysstr[MAX_LINE];
    command = fopen("command.bat", "w");
    sysstr[0] = path[0];
    sysstr[1] = ':';
    sysstr[2] = '\n';
    sysstr[3] = '\0';
    fputs(sysstr, command);
    strcpy(sysstr, "cd ");
    strcat(sysstr, path);
    strcat(sysstr, "\n");
    fputs(sysstr, command);
    fputs("DIR *.* / s > filenamelist.txt", command);//这里用/ b可以实现仅对本目录的提取（但需要修改下面的格式化读取部分），
    //                                                  而/ s可以保证完全读取包括其子目录下文件在内的所有文件
    fclose(command);
    system("command.bat");
    strcpy(sysstr, path);
    strcat(sysstr, "\\filenamelist.txt");
    //if (strcmp(sysstr, "E:\\学习\\Dian熬测\\题目包\\题目包\\trainingDigits\\filenamelist.txt") == 0)printf("11111"); 
    //else printf("00000");//测试
    list = fopen(sysstr, "r+");
    while (fgets(buf, MAX_LINE, list) != NULL)
    {
        char aim[MAX_PATH];
        char path[MAX_PATH];
        char finalpath[MAX_PATH];
        len = strlen(buf);
        buf[len - 1] = '\0';
        /************************这段直接采用本人暑假写的文件批量读取函数的部分内容********************/
        if (buf[0] == 32 && buf[2] == ':' && (buf[1] == 'C' || buf[1] == 'D' || buf[1] == 'E' || buf[1] == 'F') && buf[4] != 36) {
            int ori;
            for (ori = 1; buf[ori] != 32 || buf[ori + 1] != -75 || buf[ori + 2] != -60; ori++) {
                path[ori - 1] = buf[ori];
            }
            path[ori - 1] = '\0';
            char help[] = "0";
            help[0] = 92;
            //这里可选打印完整路径
            ///strcat(path, help);

        }
        if (buf[0] == '2'&&buf[1] == '0'&&buf[4] == '/'&&buf[21] != '<'&&buf[36] != 36) {


            if (buf[36] != 'f' || buf[37] != 'i' || buf[40] != 'n' || buf[43] != 'e' || buf[44] != 'l') {
                

                strcpy(aim, &buf[36]);
                //strcpy(finalpath, path);
                strcpy(finalpath, aim);
                printf("%s\n", finalpath);
                ++nums;
            }

        }
        /****************************************就是这段**********************************/
    }
    nums--;//去掉filenamelist.txt文件自己
    fclose(list);
    remove(sysstr);
    return nums;
}

#endif
#endif
