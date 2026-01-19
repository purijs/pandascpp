#include <iostream>
#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <pybind11/stl.h>
#include <vector>
#include <string>

namespace py = pybind11;

py::array_t<bool> contains_any(const py::array_t<py::object>& strings, const std::vector<std::string>& patterns) {

    py::buffer_info buf = strings.request();
    py::object* str_ptr = static_cast<py::object*>(buf.ptr);
    size_t size = buf.size;

    auto result = py::array_t<bool>(size);
    bool* data_ptr = result.mutable_data();

    for (int i=0; i<size; i++) {
        std::string_view text = py::cast<std::string_view>(py::str(str_ptr[i]));
        bool found = false;

        for (const auto& pattern : patterns) {

            if (memmem(text.data(), text.size(), pattern.data(), pattern.size()) != nullptr) {
                found = true;
                break;
            }
        }
        data_ptr[i] = found;
    }

    return result;
}

PYBIND11_MODULE(pandasregexcpp, m) {
    m.def("contains_any", &contains_any, py::arg("input_string"), py::arg("patterns"),
          "Check if the input string contains any of the given regex patterns.");
};