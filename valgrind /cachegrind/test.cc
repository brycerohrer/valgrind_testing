int a[10001];
int b[10001];

int main() {

  for (int j = 1; j < 10; j++) {
    for(int i=1; i<10000; i++) {
      a[i] *= b[i];
    }
  }
}
