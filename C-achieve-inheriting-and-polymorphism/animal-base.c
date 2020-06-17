/*
 * =============================================================================
 *
 *       Filename:  animal-base.c
 *
 *    Description:  animal base class.
 *
 *        Created:  12/31/2012 12:27:27 PM
 *
 *         Author:  Fu Haiping (forhappy), haipingf@gmail.com
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "animal-base.h"

 /* ����Ĺ��캯������Ҫ��ʾ���� */
animal_t * animal_init(char *name)
{
	assert(name != NULL);
	size_t name_len = strlen(name);

	animal_t *animal = (animal_t *)malloc(sizeof(animal_t)
		+ sizeof(animal_ops_t) + name_len + 1);
	memset(animal, 0, (sizeof(animal_t) + sizeof(animal_ops_t)
		+ name_len + 1));
	animal->name = (char *)animal + sizeof(animal_t);
	memcpy(animal, name, name_len);//void *memcpy(void *dest, const void *src, size_t n);��src�Ŀ�ʼλ�ÿ���n���ֽڵ����ݵ�dest
	animal->animal_ops = (animal_ops_t *)((char *)animal
		+ sizeof(animal_t) + name_len + 1);

	return animal;
}

/* ������йز�������ԣ��ߣ�˵�ȵ� */
void animal_eat(animal_t *animal, char *food)
{
	animal->animal_ops->eat(food);//ָ��animal_t���������animal_ops����һ�������װ��
	return;
}

void animal_walk(animal_t *animal, int steps)
{
	animal->animal_ops->walk(steps);
	return;
}

void animal_talk(animal_t *animal, char *msg)
{
	animal->animal_ops->talk(msg);
	return;
}

/* �����������������Ҫ��ʾ���� */
void animal_die(animal_t *animal)
{
	assert(animal != NULL);

	free(animal);
	return;
}