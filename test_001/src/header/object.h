//�I�u�W�F�N�g�����ۂ̊�{�ƂȂ�N���X

#pragma once
#include "header\define.h"
#include "header\impact.h"


class Object : public Impact
{
public:
	ofImage graphics;//�摜���������߂̕ϐ���錾
	float position_x, position_y;//�|�W�V����
	float graphics_position_x, graphics_position_y;//�摜�|�W�V����
	float alpha, a_speed;//���u�����h�p�ϐ��ƃ��l���Z�̑����ϐ�

	void setup(float pos_x, float pos_y, char* path, float alpha_speed = 255, float radius = -1);//����������(x�̏����ʒu,y�̏����ʒu,�摜�ւ̑��΃p�X,���u�����h�̑���,�~�̏ꍇ�͔��a�����)
	void update(float moved_x = 0.0f, float moved_y = 0.0f, float rate = 1.0f);//�A�j���[�V���������B(1�t���[���̈ړ��ʂ�moved_x,moved_y�ɏ���rate�͈ړ��{��1.0f�ň�{)
	void draw(bool wire = false);//�`��

	void mouseMovedUpdate(int x, int y);//ofApp::mouseMoved(int x,int y)�̒��ɋL�q����B�}�E�X�𓮂������Ƃ��Ƀq�b�g����������鏈���B
	void mousePressedUpdate(int x, int y, int button, int kind_button);//ofApp::mousePressedUpdate(int x, int y, int button)�̒��ɋL�q����B�}�E�X���q�b�g���Ă���Ƃ��Ƀ{�^�����������Ƃ��̏����B
	void mouseReleasedUpdate(int x, int y, int button, int kind_button);//ofApp::mouseReleasedUpdate(int x, int y, int button)�̒��ɋL�q����B�}�E�X���q�b�g���Ă���Ƃ��Ƀ{�^���𗣂����Ƃ��̏����B

};