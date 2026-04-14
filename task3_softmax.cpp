#include <iostream>
#include <iomanip>
#include <cmath>
#include <windows.h>
using namespace std;

const int STYLE_NUM = 4;  // 文体数量

/**
 * 数值稳定的Softmax函数
 * @param scores: 输入分数数组（不会被修改）
 * @param probs: 输出概率数组（需要预先分配空间）
 * @param n: 数组长度
 */
void softmax_stable(const double scores[], double probs[], int n) {
    // 步骤1: 找最大值（防止指数溢出）
    double max_score = scores[0];
    for (int i = 1; i < n; i++) {
        if (scores[i] > max_score) {
            max_score = scores[i];
        }
    }
    
    // 步骤2: 减去最大值后取指数，同时计算总和
    double sum = 0.0;
    for (int i = 0; i < n; i++) {
        probs[i] = exp(scores[i] - max_score);  // 临时存储 e^(s_i - max)
        sum += probs[i];
    }
    
    // 步骤3: 归一化（除以总和）
    for (int i = 0; i < n; i++) {
        probs[i] /= sum;
    }
}

/**
 * 查找概率数组中的最大值索引
 * @param probs: 概率数组
 * @param n: 数组长度
 * @return: 最大值的索引
 */
int find_max_index(const double probs[], int n) {
    int max_idx = 0;
    for (int i = 1; i < n; i++) {
        if (probs[i] > probs[max_idx]) {
            max_idx = i;
        }
    }
    return max_idx;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    double scores[STYLE_NUM];
    double probs[STYLE_NUM];
    
    const char* style_names[STYLE_NUM] = {"记叙文", "议论文", "散文", "诗歌"};
    
    // 读取输入的4个分数
    for (int i = 0; i < STYLE_NUM; i++) {
        cin >> scores[i];
    }
    
    // 调用Softmax函数计算概率
    softmax_stable(scores, probs, STYLE_NUM);
    
    // 找出概率最高的文体
    int max_idx = find_max_index(probs, STYLE_NUM);
    
    // 输出结果（保留1位小数）
    cout << fixed << setprecision(1);
    for (int i = 0; i < STYLE_NUM; i++) {
        cout << style_names[i] << ": " << probs[i] * 100 << "%";
        if (i < STYLE_NUM - 1) {
            cout << " ";
        }
    }
    cout << endl;
    
    cout << "最高概率文体：" << style_names[max_idx] 
         << "（" << probs[max_idx] * 100 << "%）" << endl;
    
    return 0;
}