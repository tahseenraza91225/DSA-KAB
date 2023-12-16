#include <stdio.h>
#include <string.h>
#define MAX 1005
#define MOD 4

struct student {
  char name[25];
  char roll[15];
  int age;
  int group;
};

int n, k, m, cnt[MOD];
char command[5];
struct student students[MAX];

int get_group(char name[], int age) {
  int sum = 0, i;
  for (i = 0; name[i]; i++)
    sum += name[i];
  return (sum + age) % MOD;
}

void print_students(int group, char branch[]) {
  int i, flag = 0;
  for (i = 0; i < n; i++) {
    if (students[i].group == group) {
      if (strcmp(students[i].roll + 5, branch) == 0) {
        flag = 1;
        printf("%s ", students[i].name);
      }
    }
  }
  if (!flag) printf("-1");
  printf("\n");
}

int main() {
  int i;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%s", students[i].name);
    scanf("%s", students[i].roll);
    scanf("%d", &students[i].age);
    students[i].group = get_group(students[i].name, students[i].age);
    cnt[students[i].group]++;
  }

  while (1) {
    scanf("%s", command);
    if (command[0] == 'c') {
      scanf("%d", &k);
      printf("%d\n", cnt[k]);
    } else if (command[0] >= '0' && command[0] <= '3') {
      m = command[0] - '0';
      char branch[5];
      scanf("%s", branch);
      print_students(m, branch);
    } else if (command[0] == 'e') {
      break;
    }
  }

  return 0;
}