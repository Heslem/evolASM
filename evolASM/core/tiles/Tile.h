#include <sfml.h>
#include <core/render/Sprite.h>

/// <summary>
/// Base class for all tiles
/// </summary>
class Tile
    : public sf::Drawable, public sf::Transformable
{
    enum class PhysicalType
    {
        Gas,
        Liquid,
        Solid
    };

    bool _isDirty;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

public:

    Sprite mSprite;

	Tile();
	~Tile();

    virtual void tick() {}

    void setDirty() noexcept { _isDirty = true; }
    const bool& isDirty() const noexcept { return _isDirty; }
};