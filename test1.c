#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int	main(void)
{
	int upper_limit;   // 上限値
	int random_number; // ランダムな整数
	int i = 1000;
	printf("上限値を入力してください: ");
	scanf("%d", &upper_limit);

	// 乱数生成器のシードを設定

	srand(time(NULL));
	while (i)
	{
		// 1から上限値までのランダムな整数を生成
		random_number = rand() % upper_limit + 1;

		// ランダムな整数を出力
		printf("%d ", random_number);
		i--;
	}
	return (0);
}