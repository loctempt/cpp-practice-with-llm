#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

const int EXPERT_NUM = 3; // 专家数量
const int FEAT_DIM = 5;   // 特征维度

// 第一题：计算两个向量的点积
double dot_product(double a[], double b[], int n) {
    double sum = 0.0;
    for (int i = 0; i < n; ++i) {
        sum += a[i] * b[i];
    }
    return sum;
}

// 第二题：计算矩阵与向量的乘积
void matrix_vector_mult(double matrix[][FEAT_DIM], double vec[], double result[]) {
    for (int i = 0; i < EXPERT_NUM; ++i) {
        result[i] = 0.0;
        for (int j = 0; j < FEAT_DIM; ++j) {
            result[i] += matrix[i][j] * vec[j];
        }
    }
}

// 第三题：数值稳定的Softmax函数
void softmax_stable(double scores[], double probs[], int n) {
    // 1. 找最大值
    double max_val = scores[0];
    for (int i = 1; i < n; ++i) {
        if (scores[i] > max_val) {
            max_val = scores[i];
        }
    }

    // 2. 减去最大值后求exp并累加
    double sum_exp = 0.0;
    for (int i = 0; i < n; ++i) {
        probs[i] = exp(scores[i] - max_val);
        sum_exp += probs[i];
    }

    // 3. 归一化
    for (int i = 0; i < n; ++i) {
        probs[i] /= sum_exp;
    }
}

int main() {
    double article[FEAT_DIM];
    double expert_scores[EXPERT_NUM];

    // 专家专长矩阵(Key)：每行是一位专家的专长特征向量
    double experts[EXPERT_NUM][FEAT_DIM] = {
        {0.9, 0.5, 0.2, 0.7, 0.8}, // 结构专家: 重视逻辑和术语
        {0.3, 0.2, 0.9, 0.6, 0.2}, // 文采专家: 重视情感和修辞
        {0.8, 0.9, 0.1, 0.5, 0.7}  // 逻辑专家: 重视逻辑连接和正式度
    };
    
    // 读取输入：文章特征向量
    for (int i = 0; i < FEAT_DIM; ++i) {
        if (!(cin >> article[i])) return 0; 
    }
    // 读取输入：专家基础分
    for (int i = 0; i < EXPERT_NUM; ++i) {
        cin >> expert_scores[i];
    }

    // 步骤1 - 计算注意力分数 (调用矩阵乘法)
    double attention_scores[EXPERT_NUM];
    matrix_vector_mult(experts, article, attention_scores);

    // 步骤2 - 生成注意力权重 (调用Softmax)
    double weights[EXPERT_NUM];
    softmax_stable(attention_scores, weights, EXPERT_NUM);

    // 步骤3 - 加权评分 (调用点积函数)
    double final_score = dot_product(weights, expert_scores, EXPERT_NUM);

    // 输出结果 (保留1位小数)
    cout << fixed << setprecision(1);
    cout << "专家权重: 结构: " << weights[0] * 100 << "% "
         << "文采: " << weights[1] * 100 << "% "
         << "逻辑: " << weights[2] * 100 << "%" << endl;
    cout << "最终评分: " << final_score << endl;

    return 0;
}