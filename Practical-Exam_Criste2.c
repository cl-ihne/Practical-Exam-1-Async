#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void mainmenudisplay() {

	printf("\t\tBO'S COFFE MENU\n");
	printf("----------------------------------------------------------------\n");
	printf(" BREWED COFFEE\n");
	printf("----------------------------------------------------------------\n");
	printf("\t\t\tSMALL\t\tMEDIUM\t\tLARGE\n");
	printf("Drip\t\t\t95\t\t110\t\t125\n");
	printf("French Press\t\t95\t\t110\t\t125\n");
	printf("----------------------------------------------------------------\n");
	printf(" ESPRESSO\n");
	printf("----------------------------------------------------------------\n");
	printf("\t\t\tSMALL\t\tMEDIUM\t\tLARGE\n");
	printf("Espresso\t\t105\t\t120\t\t140\n");
	printf("Espresso Macchiato\t105\t\t120\t\t140\n\n");
	printf("================================================================\n");
	printf("\t\t    HOT || ICED\n");
	printf("================================================================\n");
	printf("\t\t\tSMALL\t\tMEDIUM\t\tLARGE\n");
	printf("Caffe Americano\t\t110\t\t125\t\t140\n");
	printf("Cappuccino\t\t120\t\t135\t\t150\n");
	printf("Caffe Latte\t\t120\t\t135\t\t150\n");
	printf("Caffe Mocha\t\t135\t\t150\t\t165\n");
	printf("Caramel Latte\t\t145\t\t160\t\t175\n\n");
	printf("White Chocolate \n");
	printf("Mocha Espresso \t\t145\t\t160\t\t175\n\n");
	printf("----------------------------------------------------------------\n");
	printf(" FROCCINO\n");
	printf("----------------------------------------------------------------\n");
	printf("================================================================\n");
	printf("\t\t ICED BLENDED COFFEE\n");
	printf("================================================================\n");
	printf("\t\t\tSMALL\t\tMEDIUM\t\tLARGE\n");
	printf("Mocha\t\t\t140\t\t155\t\t170\n");
	printf("Caramelo\t\t140\t\t155\t\t170\n\n");
	printf("Iced Blended\n");
	printf("Cookies and Cream\t150\t\t165\t\t180\n\n");
	printf("Coffee Jelly\t\t160\t\t175\t\t190\n\n");
	printf("Iced Blended\n");
	printf("White Chocolate Mocha\t160\t\t175\t\t190\n");
	printf("\n");
	printf(" Customize Your Beverage\n");
	printf(" ADD-ONS\n");
	printf("   Assorted Cookies +30\n");
	printf("   White Mocha +20\n");
	printf("   Heavy Cream +20\n");
	printf("   Coffee Jelly Sinkers +20\n");
	printf(" Substitute\n");
	printf("   Hand Pour +20\n");
	printf("   Cold Brew +20\n");
	printf("----------------------------------------------------------------\n");
}

const char items[][100]={
"Drip","French Press","Espresso","Espresso Macchiato",
"Caffe Americano","Cappuccino","Caffe Latte","Caffe Mocha","Caramel Latte","White Chocolate Mocha Espresso",
"Mocha","Caramelo","Iced Blended Cookies and Cream","Coffee Jelly","Iced Blended White Chocolate Mocha"};

const int mprice[][100]={
{95,110,125},{95,110,125},{105,120,140},{105,120,140},
{110,125,140},{120,135,150},{120,135,150},{135,150,165},{145,160,175},{145,160,175},
{140,155,170},{140,155,170},{150,165,180},{160,175,190},{160,175,190}};

const char addOns[][100]={
"Assorted Cookies","White Mocha","Heavy Cream","Coffee Jelly Sinkers","Hand Pour","Cold Brew","No","no","None","none"};

const int addOns_price[]={
30,20,20,20,20,20,0,0,0,0};

int indexSearch(char input[100]) {
	int i;
	int index;
	
	for(i=0;i<=80;i++){

	if (strcmp(input,items[i]) == 0){ 
      index = i;
    }	
	if (strcmp(input,addOns[i]) == 0){
      index = i;
    }	
	}
		
	return index;
}

int askSize(char size[100]) { 
	int drinkSize = 0;

	if (strcmp(size,"Small") == 0){
       drinkSize = 0;
    }
	if (strcmp(size,"Medium") == 0){
       drinkSize = 1;
    }
	if (strcmp(size,"Large") == 0){
       drinkSize = 2;
    }
	
	return drinkSize;
}

void systemframework(){

	char order[100][100], drinkSize[100], horc[10], answer[100], receiptfile[100], additional_o[100][100], yorn[5];
	int paycment, i, additionorders, drinkAddons[60], quantity_o[60], size, price[60], totalcost, stotalcost[60], index, xstotalcost[60];
	int trackOrders = 0;
	
	FILE *fp; 
	strcpy(receiptfile, "receipt.csv");	
	fp = fopen(receiptfile, "w");
	
	printf("Hi! What's your order? ");
	scanf(" %[^\n]",&order[0]); 
	
	for (i=0;(strcmp(order[i],"Done") != 0);i++){ 
	
	index = indexSearch(order[i]); 
	
	while (index<0 || index>16){
		printf("Invalid item!\n");
		printf("Please try again\n");
		printf("Hi! What's your order? ");
		scanf(" %[^\n]",&order[i]);
		index = indexSearch(order[i]); 
	}
	
	printf("How many? ");
	scanf("%i",&quantity_o[i]);

	printf("What size? ");
	scanf("%s",drinkSize);
	
	size = askSize(drinkSize); 
	price[i] = mprice[index][size];
	
	if (index <= 9 && index >=4){ 
	printf("Do you want it HOT or ICED? ");
	scanf("%s",horc);
	strcat(strcat(order[i], " "),horc);
	}
	
	if (index<=15 && index>=10){
	printf("Any Add-ons/Substitute? ");
	scanf(" %[^\n]s",additional_o[i]);
	additionorders = indexSearch(additional_o[i]);
	while (additionorders < 0 || additionorders > 10 ){
		printf("Invalid add-on!\n");
		printf("Please try again\n");
		printf("Any Add-ons/Substitute? ");
		scanf("  %[^\n]s",additional_o[i]);
		
		additionorders = indexSearch(additional_o[i]);
	}
	drinkAddons[i] = addOns_price[additionorders];
	xstotalcost[i] = drinkAddons[i] * quantity_o[i];
	if (drinkAddons[i] <=0 || drinkAddons[i] >30){
	}
}
	
	
	stotalcost[i] = (price[i]*quantity_o[i]);
	totalcost = totalcost + stotalcost[i]+ xstotalcost[i]; 
	trackOrders = trackOrders + 1; 
	printf("Anything Else? ");
	scanf(" %[^\n]s",order[i+1]);
	strcat(strcat(order[i], " "),drinkSize); 
	}		
	
	char title[4][60]= {"Item","Price","Quantity","Subtotal"};
	printf("\n%-50s\t\t\t%s \t\t%s \t%s \n",title[0],title[1],title[2],title[3]);
	fprintf(fp,"Item, Price, Quantity, Subtotal\n");
	
	int length = trackOrders;
	

	for (i=0;i<length;i++){
		printf("%-50s\t\t\t%i\t\t%i\t\t %d \n",&order[i],price[i],quantity_o[i],stotalcost[i]);
		fprintf(fp,"%s, %i, %i, %d\n",&order[i],price[i],quantity_o[i],stotalcost[i]);
	}
	
	for (i=0;i<length;i++){ 
	if (drinkAddons[i]!=0){
		int xquantity = quantity_o[i];
		printf("%-50s\t\t\t%i\t\t %i\t\t %d \n",&additional_o[i],drinkAddons[i],xquantity,xstotalcost[i]);
		fprintf(fp,"%s,%i,%i,%d\n",&additional_o[i],drinkAddons[i],xquantity,xstotalcost[i]);
	}	
	}
	
	printf("\nTotal Php\t\t\t\t\t\t\t\t\t\t\t%i",totalcost);
	fprintf(fp,"Total Php,"","",%i",totalcost);
	
	printf("\nWould you like to confirm your order [Yes/No]? ");
	scanf(" %[^\n]s",yorn);
	
	if (strcmp(yorn,"Yes") != 0){
	fclose(fp);
	systemframework();
	}
	
	if (strcmp(yorn,"Yes") == 0){
    
	printf("How much is your cash? ");
	scanf(" %i",&paycment);
	
	fprintf(fp,"\nCash:,"","", %i",paycment);
	int change = paycment - totalcost;
	
	if (change < 0 ){
	printf("Insufficient Funds!");
	fprintf(fp,"\nInsufficient Funds!");
return;
}
	printf("Your change is: %d",change);
	printf("\nSaving your transaction into receipt.csv...");
	printf("\nThank you for visiting Bo's Coffee! See you again!");
	fprintf(fp,"\nChange:,"","", %d",change);
    }
	fclose(fp);

return;	
}
int main(void) {
	
	mainmenudisplay(); 
	systemframework(); 
	return 0;
}
