#include <iostream>
#include <string>

using namespace std;

int Length(string names) {
    int k = 0;
    for (int j = 0; j < names.size(); ++j) {
        k += names[j];
    }
    return k;
}

int main() {

    int d[30] = {0, 180, 793, 763, 13926, 74067,
                 6, 919, 324, 70, 956, 925,
                 84, 27, 45, 98814, 178, 51,
                 932, 8, 12, 39, 434, 378,
                 1, 619, 97, 71, 871, 5
    };//保证第一个设置为0

    string names[30] = {
            "zhnagsan", "lisi", "wangwu", "gongchandnag", "guomindang", "maozedong",
            "zhouenlai", "lidazhao", "chenduxiu", "tuling", "nimapi", "zhonguop",
            "meiguo", "yidu", "kebi", "qiaodan", "zhoujielun", "chenyixun",
            "nuibeier", "cjiajia", "jiava", "python", "deeplearning", "xuexi",
            "nvpengyou", "danshengou", "meimingzi", "feiqi", "hhhh", "nihui"
    };

    string new_name[36];

    bool flag[36];
    for (int j = 0; j < 36; ++j) {
        flag[j] = false;
    }
    int length;
    int position;
    int index;
    //构建哈希表
    for (int i = 0; i < 30; ++i) {
        length = Length(names[i]);
        index = 0;
        while (true) {
            position = (length + d[index]) % 31;
            if (index == 29) {
                cout << names[i] << "无法找到正确的位置" << endl;
                break;
            }
            if (flag[position]) {
                index++;
            } else {

                new_name[position] = names[i];
                flag[position] = true;
                break;
            }

        }

    }

//查找关键字
    for (int l = 0; l < 30; ++l) {
        length = Length(names[l]);
        index = 0;
        while (true) {
            position = (length + d[index]) % 31;
            if (index == 29) {
                cout << names[l] << "不存在" << endl;
                break;
            }
            if (flag[position] && new_name[position] == names[l]) {
                cout << names[position] << ":" << position << endl;
                break;
            } else {

                index++;
            }

        }
    }

    return 0;
}