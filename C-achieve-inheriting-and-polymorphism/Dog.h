#include "animal-base.h"

typedef struct dog_s_ dog_t;

struct dog_s_ {
	animal_t base; /* �̳��� animal ���� */

	/* ���»���������� dog ��ص����Ժͷ���(����ָ��), ��: */
	/* char *owner; // dog ������ */
	/* void (*hunt)(const char *rabbit); // ����Ȯ */
};

extern dog_t * dog_init();
extern void dog_die(dog_t * dog);