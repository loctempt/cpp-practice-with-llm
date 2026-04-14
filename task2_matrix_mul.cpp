#include <iomanip>
#include <iostream>
#include <cstring>
using namespace std;

const int STYLE_NUM = 4;  // 文体数量
const int FEAT_DIM = 5;   // 特征维度

// 计算矩阵与向量的乘积：result = matrix * vector
// @param matrix: 文体特征矩阵 (STYLE_NUM x FEAT_DIM)
// @param vec: 文章特征向量 (FEAT_DIM)
// @param result: 输出结果向量 (STYLE_NUM)
void matrix_vector_mult(double matrix[][FEAT_DIM], double vec[],
                        double result[]) {
  // TODO: 实现矩阵乘法（双重循环）
  for (int i = 0; i < STYLE_NUM; i++) {
    for (int j = 0; j < FEAT_DIM; j++) {
      result[i] += matrix[i][j] * vec[j];
    }
  }
}

int main() {
#ifdef DEBUG
  freopen("task2_matrix_mul.input", "r", stdin);
#endif
  double article[FEAT_DIM];
  double result[STYLE_NUM] = {0};

  // 文体特征矩阵（硬编码）
  double styles[STYLE_NUM][FEAT_DIM] = {
      {0.90, 0.10, 0.20, 0.10, 0.12},  // 记叙文：叙事性突出
      {0.10, 0.90, 0.15, 0.10, 0.05},  // 议论文：逻辑+学术双高
      {0.04, 0.15, 0.09, 0.92, 0.10},  // 散文：情感性独高
      {0.10, 0.05, 0.15, 0.30, 0.95}   // 诗歌：韵律+情感双高
  };

  const char* style_names[STYLE_NUM] = {"记叙文", "议论文", "散文", "诗歌"};

  // TODO: 读取文章特征向量
  while (cin >> article[0]) {
    memset(result, 0, sizeof(result));
    for (int i = 1; i < FEAT_DIM; i++) {
      cin >> article[i];
    }
    // TODO: 调用矩阵乘法函数
    matrix_vector_mult(styles, article, result);
    // TODO: 输出结果（保留2位小数）
    for (int i = 0; i < STYLE_NUM; i++) {
      cout << fixed << setprecision(2) << style_names[i] << ": " << result[i]
           << " ";
    };
    cout << endl;
  }

  return 0;
}