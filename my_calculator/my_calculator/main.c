//#define NOW
#ifdef NOW
#ifndef _MAIN_C
#define _MAIN_C
#include <main.h>
evening_struct training[5000];//训练样本结构体
evening_struct testing[5000];//测试样本结构体
int total_training_nums = 0;//训练样本总数
int total_testing_nums = 0;//测试样本总数

//此主函数用于进行对测试数据的标签推断以及计算正确率
//而对bmp图像的识别做成了单独的函数，可在main.h里找到声明，并可直接调用
//图像识别只初步做到了能识别，要求必须是32*32的位图，所以并没有完全达成要求
int main(void) {
    int k = 5;//k值不建议取太大，5之后的k值并不总能提升正确率，反而会极高地增加运行时间
    char *path;
    int num_of_file;
    double right_rate;
    path = (char*)malloc(sizeof(char)*MAX_PATH);
    int i = 0;
    printf("Please input the training path:\n");
    while ((path[i] = fgetc(stdin)) != '\n')i++;//读取训练数据路径
    path[i] = '\0';
    num_of_file = read_file_list(path);//步骤1专属
    read_training_data(path);//读取训练数据
    printf("Please input the testing path:\n");
    i = 0;
    while ((path[i] = fgetc(stdin)) != '\n')i++;//读取测试数据路径
    path[i] = '\0';
    read_testing_data(path);//读取测试数据
    enlabel_testing_files(k);//进行推断
    right_rate = cal_rate();//计算正确率
    printf("k = %d, %d组数据下的正确率：%lf\n", k, total_testing_nums, right_rate);
    free(path);
    return 0;
}


#endif
#endif
