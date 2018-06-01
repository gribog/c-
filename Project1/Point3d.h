#pragma once

class Vector3d;

class Point3d
{
private:
	double m_x, m_y, m_z;

public:
	Point3d(double x, double y, double z);

	void print();

	void moveByVector(const Vector3d &v);
};
