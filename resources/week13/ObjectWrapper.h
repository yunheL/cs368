/*
 * Example of a templated class
 */
#ifndef OBJECTWRAPPER_H
#define OBJECTWRAPPER_H

template <typename Object>
class ObjectWrapper {
  public:
    ObjectWrapper(const Object & initValue = Object() ) :
      value(initValue) { }

    const Object & getValue() const { return value; }
 
    void setValue( const Object & newValue ); 

  private:
    Object value;
};

// setValue is defined outside the class declaration to show how to
// write template definitions separate from their declarations
template <typename Object>
void ObjectWrapper<Object>::setValue( const Object & newValue ) {
    value = newValue;
}

#endif 
