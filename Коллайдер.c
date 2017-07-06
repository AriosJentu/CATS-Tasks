#include <stdio.h>
 
int ceilbytwo(int x){
	return x%2 == 1 ? (x/2) + 1 : x/2;
}
 
int main(){
	FILE *InputFile = fopen("linear.in", "r");
	
	int ParticlesCount;
	fscanf(InputFile, "%i", &ParticlesCount);
	
	int CurrentPos; 
	int CurrentDir;
	
	int Stack[ParticlesCount];
	int Times[ParticlesCount];

	int StackHigher = 0;
	int TimesHigher = 0;

	for (int i = 0; i < ParticlesCount; i++) {
		
		fscanf(InputFile, "%i %i", &CurrentPos, &CurrentDir);

		if(CurrentDir == 1) {
		
			Stack[StackHigher] = CurrentPos;
			StackHigher++;
		
		} else if(StackHigher > 0) {
		
            StackHigher--;  
			Times[TimesHigher] = ceilbytwo(CurrentPos - Stack[StackHigher]);
			TimesHigher++;
		}
	}

	int TimesCount;
	fscanf(InputFile, "%i", &TimesCount);

	int TimeMoments[TimesCount];
	int ResultArray[TimesCount];

	for(int i = 0; i < TimesCount; i++){
		fscanf(InputFile, "%i", &TimeMoments[i]);
		ResultArray[i] = 0;
	}
	fclose(InputFile);

	for(int i = 0; i < TimesHigher; i++){

		if(Times[i] <= TimeMoments[0]){
			ResultArray[0] += 2;
			continue;
		}
	
		int Left = 0; 
		int Right = TimesCount;

		while(Right - Left > 1){
		
			int mid = Left + (Right - Left) / 2;
			if (Times[i] > TimeMoments[mid]) {
				
				Left = mid;
			
			} else {
				
				Right = mid;
			}
		}
		ResultArray[Right] += 2;
	}

	FILE* OutputFile = fopen("linear.out", "w");
	for(int i = 0; i < TimesCount; i++) {

		if (i > 0) {
			ResultArray[i] += ResultArray[i-1];			
		}

		printf("%i\n", ParticlesCount - ResultArray[i]);
		fprintf(OutputFile, "%i ", ParticlesCount - ResultArray[i]);
	}

	fclose(OutputFile);
}