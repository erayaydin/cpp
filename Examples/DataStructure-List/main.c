#include <stdio.h>
#include <math.h>

struct Ifade {
	int katsayi;
	int us;
	int taban;
	Ifade* sonraki;
};

Ifade* bas = NULL;
Ifade* son = NULL;

void yazdir() {
	Ifade* gezici = bas;
	while(gezici != NULL){
		printf("%dx%d^%d\n", gezici->katsayi, gezici->taban, gezici->us);
		gezici = gezici->sonraki;
	}
}

void birlestir() {
	Ifade* gezici = bas;
	while(gezici != NULL) {
		Ifade* gezici2 = gezici->sonraki;

		int yeniKatsayi = gezici->katsayi;
		while(gezici2 != NULL && gezici2->taban == gezici->taban && gezici2->us == gezici->us){
			yeniKatsayi += gezici2->katsayi;
			gezici2 = gezici2->sonraki;
		}
		if(yeniKatsayi != gezici->katsayi){
			gezici->katsayi = yeniKatsayi;
			gezici->sonraki = gezici2;
		}

		gezici = gezici->sonraki;
	}
}

int toplam() {
	int toplam = 0;
	Ifade* ifade = bas;
	while (ifade != NULL){
		toplam += ifade->katsayi * pow(ifade->taban, ifade->us);
		ifade = ifade->sonraki;
	}

	return toplam;
}

void search(int total) {
	Ifade* ifade = bas;
	while(ifade != NULL){
		int calc = ifade->katsayi * pow(ifade->taban, ifade->us);

		if(calc == total){
			printf("--> %dx%d^%d\n", ifade->katsayi, ifade->taban, ifade->us);
		}
		ifade = ifade->sonraki;
	}
}

int main() {
	int katsayi, us, taban;
	FILE* fp;
	fp = fopen("data.txt", "r");
	char line[7];

	while(fgets(line, sizeof line, fp) != NULL) {
		sscanf(line, "%d %d %d", &katsayi, &taban, &us);

		Ifade* ifade = (Ifade*)malloc(sizeof(Ifade));
		ifade->katsayi = katsayi;
		ifade->taban   = taban;
		ifade->us      = us;
		ifade->sonraki = NULL;

		if(bas == NULL){
			bas = ifade;
			son = ifade;
		} else if(ifade->taban < bas->taban || (ifade->taban == bas->taban && ifade->us < bas->us)) {
			ifade->sonraki = bas;
			bas = ifade;
		} else {
			Ifade* gezici = bas;
			while(gezici != NULL){

				if(gezici->sonraki->taban > ifade->taban || (gezici->sonraki->taban == ifade->taban && gezici->sonraki->us >= ifade->us)){
					break;
				}
				gezici = gezici->sonraki;
			}

			ifade->sonraki = gezici->sonraki;
			gezici->sonraki = ifade;
		}
	}
	
	int secenek;
	do {
		printf("İşlemler\n");
		printf("1) Listeyi Yazdır\n");
		printf("2) Birleştir\n");
		printf("3) Arama\n");
		printf("4) Toplam Göster\n");
		printf("5) Çıkış\n");

		printf("İşlem: ");
		scanf("%d", &secenek);

		switch(secenek) {
			case 1:
				yazdir();
			break;

			case 2:
				birlestir();
			break;

			case 3:
				int total;
				printf("Sonuç Ara: ");
				scanf("%d", &total);

				printf("Sonuçlar\n");
				search(total);
			break;

			case 4:
				printf("Toplam: %d\n", toplam());				
			break;
		}
	} while(secenek != 5);
}
