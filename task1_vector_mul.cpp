#include <iomanip>
#include <iostream>
using namespace std;

// 计算两个向量的点积
// @param a: 第一个向量
// @param b: 第二个向量
// @param n: 向量维度
// @return: 点积结果
double dot_product(double a[], double b[], int n) {
  // TODO: 实现点积计算
  double accumulator = 0;
  for (int i = 0; i < n; i++) {
    accumulator += a[i] * b[i];
  }
  return accumulator;
}

int main() {
#ifdef DEBUG
  freopen("vector_mul.input", "r", stdin);
#endif
  double user[5];
  double threshold;

  // 标准模板向量（硬编码）
  double _template[5] = {0.9, 0.8, 0.1, 0.6, 0.95};

  // TODO: 读取输入
  while (cin >> user[0]) {
    for (int i = 1; i < 5; i++) {
      cin >> user[i];
    }
    // TODO: 计算相似度
    // TODO: 输出结果（保留4位小数）
    cout << fixed << setprecision(4)
         << "Similarity: " << dot_product(user, _template, 5) << endl;
  }

  return 0;
}