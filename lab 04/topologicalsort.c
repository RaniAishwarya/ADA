#include <stdio.h>
#include <stdlib.h>

void main() {
    int a[10][10], n;
    printf("enter the number of vertices in the graph : \n");
    scanf("%d", &n);
    printf("enter the elements of the adjacency matrix : \n");
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    topological(a, n);
}

void topological(int a[10][10], int n) {
    int indegree[10];
    int sum;
    int s[10], t[10];
    for(int j=0; j<n; j++){
        sum = 0;
        for(int i=0; i<n; i++) {
            sum = sum + a[i][j];
        }
        indegree[j] = sum;
    }

    int top = -1;
    for(int i=0; i<n; i++) {
        if(indegree[i] == 0) {
            top = top + 1;
            s[top] = i;
        }
    }

    while(top != -1) {
        int u = s[top];
        top = top - 1;
        t[top++] = u;
        for(int j=0; j<n; j++) {
            if(a[u][j] == 1) {
                indegree[j]--;
                if(indegree[j] == 0) {
                top++;
                s[top] = j;
                }
            }
        }
    }

    printf("topological sort : \n");
    for(int i=0; i<n; i++) {
        printf("%d", t[i]);
    }
}
