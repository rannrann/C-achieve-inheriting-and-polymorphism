/*
 * =============================================================================
 *
 *       Filename:  animal-base.h
 *
 *    Description:  animal base class.
 *
 *        Created:  12/31/2012 11:36:43 AM
 *
 *         Author:  Fu Haiping (forhappy), haipingf@gmail.com
 *        Company:  ICT ( Institute Of Computing Technology, CAS )
 *
 * =============================================================================
 */
#ifndef _ANIMAL_H_
#define _ANIMAL_H_

typedef struct animal_s_ animal_t;
typedef struct animal_ops_s_ animal_ops_t;


/* �����࣬�����ж�����Ļ���,Ҳ�ǳ����� */
struct animal_s_ {
	char *name; /*< ��������� */
	animal_ops_t *animal_ops; /* ����Ļ�����Ϊ */
};

/* ����Ļ�����Ϊ */
struct animal_ops_s_ {
	/* �������ʲôʳ�� */
	void(*eat)(char *food);//void(*eat)����������ָ�룬����void����
	/* �������˶��ٲ� */
	void(*walk)(int steps);
	/* ������˵ʲô */
	void(*talk)(char *msg);
};

/* ����Ĺ��캯������Ҫ��ʾ���� */
extern animal_t * animal_init(char *name);//extern��ʾ�ú���������������ⲿ����

/* ������йز�������ԣ��ߣ�˵�ȵ� */
extern void animal_eat(animal_t *animal, char *food);
extern void animal_walk(animal_t *animal, int steps);
extern void animal_talk(animal_t *animal, char *msg);

/* �����������������Ҫ��ʾ���� */
extern void animal_die(animal_t *animal);

#endif  /* _ANIMAL_H_ */