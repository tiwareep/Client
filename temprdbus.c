/**
 * Convert a GVariant into an equivalent Scheme Object.
 */
Scheme_Object *
g_variant_to_scheme_object (GVariant *gv)
{
  GVariantType *type;

  // Special case: We'll treat NULL as void.
  if (gv == NULL)
    {
      return scheme_void;
    } // if (gv == NULL)

  // Get the type
  type = g_variant_get_type (gv);

  // ** Handle most of the basic types **

  // Integer
  else if (...)
    {
      return scheme_make_integer (...);
    } // if it's an integer

  ...

  // ** Handle the compound types **

  // Tuple
  else if (g_variant_type_is_tuple (type))
    {
      return g_variant_tuple_to_scheme_list (gv, 0, g_variant_n_children (gv));
    }
} // g_variant_to_scheme_object

Scheme_Object *
g_variant_tuple_to_scheme_list (GVariant *tuple, int index, int size)
{
  // Base case: We reached the end of the tuple
  if (index == size)
    return scheme_null; // Or whatever the empty list value is
  else
    return scheme_make_pair (g_variant_to_scheme_object (g_variant_get_child_value (tuple, index)),
                             g_variant_tuple_to_scheme_list (tuple, index+1, size));
} // g_variant_tuple_to_scheme_list

-- SamR
