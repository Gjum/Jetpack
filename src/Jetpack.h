#ifndef JETPACK_H
#define JETPACK_H

class Jetpack
{
public:
    Jetpack();
    ~Jetpack();

protected:
private:
    static Jetpack * Get ();
    static Jetpack    *JetpackPointer;
};

#endif // JETPACK_H
