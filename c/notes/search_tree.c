// search specific value inside a tree
bool search (node *tree)
{
  if (tree == NULL)
  {
    return false;
  }

  else if (50 < tree->number)
  {
    return search(tree->left);
  }

  else if (50 > tree->number)
  {
    return search(tree->right);
  }

  else
  {
    return true;
  }
}
