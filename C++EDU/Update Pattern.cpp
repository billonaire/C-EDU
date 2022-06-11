int numObjectsThisTurn = numObjects_;
for (int i = 0; i < numObjectsThisTurn; i++)
{
	objects_[i]->update();
}


class Entity {
public:
	Entity() : x_(0), y_(0){}
	virtual ~Entity(){}
	virtual void update() = 0;

	double x() const { return x_; }
	double y() const { return y_; }

	void setX(double x) { x_ = x; }
	void setY(double y) { y_ = y; }

private:
	double x_;
	double y_;
};


class World {
public:
	World() : numEntities_(0){}
	void gameLoop();

private:
	Entity* entities_[MAX_ENTITIES];
	int numEntities_;
};

void World::gameLoop() {
	while (true)
	{
		// 유저 입력 처리..

		for (int i = 0; i < numEntities_; i++)
		{
			entities_[i]->update();
		}
		// 물리, 렌더링..
	}
}


class Skeleton : public Entity {
public:
	Skeleton() : patrollingLeft_(false){}

	virtual void update() {
		if (patrollingLeft_) {
			setX(x() - 1);
			if (x() == 0) 
				patrollingLeft_ = false;
		}
		else {
			setX(x() + 1);
			if (x() == 100)
				patrollingLeft_ = true;
		}
	}

private:
	bool patrollingLeft_;
};

void Skeleton::update(double elapsed) {
	if (patrollingLeft_)
	{
		x -= elapsed;
		if (x <= 0)
		{
			patrollingLeft_ = false;
			x = -x;
		}
	}
	else {
		x += elapsed;
		if (x >= 100) {
			patrollingLeft_ = true;
			x = 100 - (x - 100);
		}
	}
}


class Statue : public Entity {
public:
	Statue(int delay) : frames_(0), delay_(delay) {}

	virtual void update() {
		if (++frames_ == delay_) {
			shootLightning();

			// 타이머 초기화
			frames_ = 0;
		}
	}

private:
	int frames_;
	int delay_;

	void shootLightning() {

	}
};