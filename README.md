# pandascpp

A high-performance C++ extension for pandas that accelerates string operations using pybind11.

## Installation

### Prerequisites

- Python 3.7+
- CMake 4.0+
- C++ compiler with C++20 support (GCC 10+, Clang 10+, MSVC 2019+)
- pandas
- numpy

### Building from Source

1. Clone the repository:
```bash
git clone <repository-url>
cd pandascpp
```

2. Create a build directory and compile:
```bash
mkdir build
cd build
cmake -DPython_EXECUTABLE=$(which python3) ..
cmake --build .
```

3. Use the module:

**Install to Python site-packages**
```bash
# From the build directory
cp pandasregexcpp*.so $(python3 -c "import site; print(site.getsitepackages()[0])")
```

**Note**: The module must be built with the same Python version you intend to use it with. If you see a `ModuleNotFoundError`, rebuild with the correct Python version using the `-DPython_EXECUTABLE` flag.


## Usage

```python
import pandas as pd
import pandasregexcpp

# Create a DataFrame with text data
df = pd.DataFrame({'text': ['hello world', 'foo bar', 'test data']})

# Check if strings contain any of the specified patterns
patterns = ['hello', 'world', 'foo', 'bar']
mask = pandasregexcpp.contains_any(df['text'].values, patterns)

# Use the mask to filter the DataFrame
filtered_df = df[mask]
```

### API Reference

#### `contains_any(input_strings, patterns)`

Check if each string in the input array contains any of the given patterns.

**Parameters:**
- `input_strings` (numpy.ndarray): Array of strings to search
- `patterns` (list of str): List of substring patterns to search for

**Returns:**
- `numpy.ndarray` of bool: Boolean array where True indicates the string contains at least one pattern

**Example:**
```python
import pandas as pd
import pandasregexcpp

df = pd.DataFrame({'text': ['apple pie', 'banana bread', 'cherry cake']})
patterns = ['apple', 'cherry']
mask = pandasregexcpp.contains_any(df['text'].values, patterns)
# mask = [True, False, True]
```
