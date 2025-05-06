package binarysearch is
   type DataArray is array(Positive range <>) of Integer;

   -- Minimalizes the average number of comparisons
   function BinarySearch (arr : DataArray; first : Integer; last : Integer; value : Integer) return Integer;

   --  Checks the midpoint every time, better best case time
   function BinarySearch1 (arr : DataArray; first : Integer; last : Integer; value : Integer) return Integer;
   
end binarysearch;