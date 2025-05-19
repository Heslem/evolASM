#include <sfml.h>
#include <core/render/Sprite.h>

/// <summary>
/// Base class for all tiles
/// </summary>
class Tile
    : public sf::Transformable
{
    bool _isDirty;


public:
    enum class PhysicalType
    {
        Gas,
        Liquid,
        Solid
    };
    PhysicalType mPhysType = PhysicalType::Gas;

	Tile();
	~Tile();

    virtual void tick() {}

    void setDirty() noexcept { _isDirty = true; }
    const bool& isDirty() const noexcept { return _isDirty; }
};