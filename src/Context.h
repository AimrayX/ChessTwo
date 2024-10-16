#include "IMoveBehaviour.h"
#include <memory>

class Context {
    
private:

    std::unique_ptr<IMoveBehaviour> mBehaviour;
    
public:

    explicit Context(std::unique_ptr<IMoveBehaviour> &&behaviour = {});
    void setBehaviour(std::unique_ptr<IMoveBehaviour> &&behaviour);
    int movePiece();
};