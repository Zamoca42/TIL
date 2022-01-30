#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define LEN 20

struct names 
{
	char given[LEN];
	char family[LEN];
};

struct reservation		// Another structure
{	
	struct names guest;	// a nested structure
	struct names host;	// one more nested structure
	char food[LEN];
	char place[LEN];

	// time
	int year;
	int month;
	int day;
	int hours;
	int minutes;

};


int main()
{
	struct reservation res = {
		.guest = {"Nick", "Carraway"},
		.host = {"Jay", "Gatsby"},
		.place = {"the Gatsby mansion"},
		.food = {"Escargot"},
		.year = 1925,
		.month = 4,
		.day = 10,
		.hours = 18,
		.minutes = 30
	};
	
	printf("Dear %s %s,\n", res.guest.given, res.guest.family);
	printf("I would like to serve you %s.\n", res.food);
	printf("Please visit %s", res.place);
	printf("on %d/%d/%d at %d:%d.\n", res.day, res.month, res.year, res.hours, res.minutes);
	printf("Sincerely,\n%s %s", res.host.given, res.host.family);

	return 0;
}