#pragma once
#include <type_traits>
#include <boost/concept_check.hpp>
#include "output_buffer.h"
#include <thread>

template <typename T, typename = void>
struct is_std_container : std::false_type { };

template <typename T>
struct is_std_container<T,
    std::void_t<decltype(std::declval<T&>().begin()),
           decltype(std::declval<T&>().end()),
           typename T::value_type>
    > : std::true_type { };

template <typename T>
inline constexpr bool is_std_container_v = is_std_container<T>::value;

class AOutputItem
{
public:
    AOutputItem(OutputBuffer &buffer, const std::string &name = "OutputItem");
    virtual ~AOutputItem();
    void stop();
    virtual void loop() = 0;
protected:
    void incMetrics(size_t cmdCount);
    void init();
protected:
    OutputBuffer &mBuffer;
    std::thread mProcessingThread;
    std::thread::id mProcessingThreadId;
    bool mWorking;
    size_t mCmdCount;
    size_t mBlockCount;
    std::string mName;
};

template <typename T>
struct OutputItemConcept {
    BOOST_CONCEPT_USAGE(OutputItemConcept) {
        static_assert(std::is_base_of_v<AOutputItem, T>, "Type is not OutputItem");
    }
};
