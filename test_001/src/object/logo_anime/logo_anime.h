#pragma once
#include "header\object.h"


class Logo_anime
{
public:
	float time;//���l�����炷���Ԃ��w�肷��ϐ�
	float alpha_blend_speed;//���l��ۑ�����ϐ��B

	float anime_x, speed_x;//x�����ւ̃A�j���[�V�������l�̕ۑ�,1�t���[���̈ړ���

	//�摜�f�[�^�������
	Object logo_D;
	Object logo_d;
	Object logo_i, logo_i_2;
	Object logo_l;
	Object logo_o;
	Object logo_p;

	void setup(float pos_x, float pos_y, float alpha_speed = 255);
	void update(float next_time_count = 0);
	void draw(bool wire = false);
};