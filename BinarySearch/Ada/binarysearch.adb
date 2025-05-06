package body binarysearch is
   function BinarySearch (arr : DataArray; first : Integer; last : Integer; value : Integer) return Integer is
      mid : Integer := (first + last) / 2;
   begin
      if last - first < 2 then
         if arr (first) = value then
            return first;
         end if;
         return -1;
      end if;

      if arr (mid) > value then
         return BinarySearch (arr, first, mid, value);
      else
         return BinarySearch (arr, mid, last, value);
      end if;
   end BinarySearch;
   
   function BinarySearch1 (arr : DataArray; first : Integer; last : Integer; value : Integer) return Integer is
      mid : Integer := (first + last) / 2;
   begin
      if last - first < 2 then
         if arr (first) = value then
            return first;
         end if;
         return -1;
      end if;

      if arr (mid) = value then
         return mid;
      elsif arr (mid) > value then
         return BinarySearch1 (arr, first, mid, value);
      else
         return BinarySearch1 (arr, mid, last, value);
      end if;
   end BinarySearch1;
end binarysearch;