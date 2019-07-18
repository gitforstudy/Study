#include "header.h"

void menu(struct Node *head)
{
	int sel;
	while (1) {
		printf("0. Print list\n");
		printf("1. Add front\n2. Add last\n3. Add mid\n4. Add last2\n5. Add selcted\n");
		printf("6. Del front\n7. Del last\n8. Del mid\n9. Del last2\n10. Del selcted\n");
		printf("11. Update front\n12. Update last\n13. Update mid\n14. Update last2\n15. Update selcted\n");
		printf("Select: ");
		fflush(stdin);
		scanf("%d", &sel);

		switch (sel) {
			case 0:
				print_list(head);
				break;
			case 1:
				add_front(head);
				break;
			case 2:
				add_last(head);
				break;
			case 3:
				head = add_mid(head);
				break;
			case 4:
				head = add_last2(head);
				break;
			case 5:
				head = add_sel(head);
				break;
			case 6:
				head = del_front(head);
				break;
			case 7:
				head = del_last(head);
				break;
			case 8:
				head = del_mid(head);
				break;
			case 9:
				head = del_last2(head);
				break;
			case 10:
				head = del_sel(head);
				break;
			case 11:
				head = update_front(head);
				break;
			case 12:
				head = update_last(head);
				break;
			case 13:
				head = update_mid(head);
				break;
			case 14:
				head = update_last2(head);
				break;
			case 15:
				head = update_sel(head);
				break;
		}
	}
}
