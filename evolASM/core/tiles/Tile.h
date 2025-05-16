#include <sfml.h>

class Tile
    : public sf::Drawable
{
    enum class PhysicalType
    {
        Gas,
        Liquid,
        Solid
    };

    bool _isDirty;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

	sf::Sprite _sprite;
public:
	Tile();
	~Tile();

    virtual void tick() {}

    void setDirty() noexcept { _isDirty = true; }
    const bool& isDirty() const noexcept { return _isDirty; }
};