#include <core/states/StateWorld.h>

class StateWorldMain final :
	public StateWorld
{
public:
	StateWorldMain();
	~StateWorldMain();

	void start() override;

	void tick() override;

	void end() override;

private:

};