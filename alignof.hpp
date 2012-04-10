#ifndef __ALIGNOF_HPP_2012_04_10__
#define __ALIGNOF_HPP_2012_04_10__

namespace NAlignOf
{
    template <class TType>
    struct TSizeIncrement: TType
    {
        char Increment;
    };

    template <class TType, unsigned Start, bool Stop>
    struct TIncreaseSizeImpl: TIncreaseSizeImpl<TSizeIncrement<TType>, Start,
        sizeof(TSizeIncrement<TType>) != Start>
    {
    };

    template <class TType, unsigned Start>
    struct TIncreaseSizeImpl<TType, Start, true>
    {
        typedef TType TType_;
    };

    template <class TType>
    struct TIncreaseSize: TIncreaseSizeImpl<TType, sizeof(TType), false>
    {
    };

    template <class TType>
    struct TAlignOf
    {
        typedef typename TIncreaseSize<TType>::TType_ TIncreased_;
        static const unsigned Value_ =
            sizeof(typename TIncreaseSize<TIncreased_>::TType_)
            - sizeof(TIncreased_);
    };
}

#endif

