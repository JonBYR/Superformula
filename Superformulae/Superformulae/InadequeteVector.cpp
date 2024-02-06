#include "InadequeteVector.h"
InadequeteVector::InadequeteVector() {

}
std::ostream& operator<<(std::ostream& os, const InadequeteVector& e) {
	os << "Please note that you must input 6 values, no more, no less." << std::endl;
	return os;
}